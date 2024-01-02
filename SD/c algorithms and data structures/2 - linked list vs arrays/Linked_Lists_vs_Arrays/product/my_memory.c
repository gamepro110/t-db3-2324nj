#include "my_memory.h"
#include "linked_list.h"

#include <stdbool.h>

static const int StartAddress = 1000;

static LinkedList freeList;
static LinkedList allocList;

void ConstructMemory(int size) {
    ListAddAfter(&freeList, StartAddress, size, NULL);
}

void DestructMemory() {
    ListRemoveAll(&allocList);
    ListRemoveAll(&freeList);
}

void printSelectedList(FILE* stream, LinkedList* list);
Element* GetLastElement(LinkedList* list);
Element* GetElementAtAddr(LinkedList* list, int addr);

int PrintList(FILE* stream) {
    if (stream == NULL) {
        return -1;
    }

    fprintf(stream, "FreeList:\n---------\n");
    printSelectedList(stream, &freeList);

    fprintf(stream, "AllocList:\n----------\n");
    printSelectedList(stream, &allocList);

    return 0;
}

/* function: ClaimMemory
 * pre: nrofBytes > 0
 * post: if no memory block of nrofBytes available return -1
 *       otherwise the first block that is large enough is claimed and the start address is returned
 */
int ClaimMemory(int nrofBytes) {
    Element* freeHead = GetLastElement(&freeList);

    if (freeHead->size < nrofBytes || nrofBytes < 1) {
        return -1;
    }

    //tODO resize freelist (variable only)
    //tODO update freelist address
    Element* elem = freeList.head;

    if (elem == NULL) {
        return -1;
    }

    elem->address += nrofBytes;
    elem->size -= nrofBytes;

    //tODO make new element for alloc list with original address of freelist and size requested
    Element* allocElem = GetLastElement(&allocList);

    int newAddr = (allocElem == NULL) ? StartAddress : (allocElem->address + allocElem->size);
    ListAddAfter(&allocList, newAddr, nrofBytes, allocElem);

    if (freeHead->size == 0) {
        ListRemoveTail(&freeList);
    }

    return newAddr;
}

void dbPrintList(const char* listName, int addr, LinkedList* list, Element* lastFound) {
    printf("%s <addr % 4d>", listName, addr);
    
    if (lastFound == NULL) {
        printf("%s ", "(NILL)");
    }
    else {
        printf("(lastElem % 3d|% 3d) ", lastFound->address, lastFound->size);
    }

    printf(":");
    Element* elem = list->head;

    while (elem != NULL) {
        printf("{% 3d|% 3d}, ", elem->address, elem->size);
        elem = elem->next;
    }

    printf("\n");
}

#define prntDb 0

/* function: FreeMemory
 * pre: Parameter addr must match the start of an allocatd memory block. Otherwhise return -1.
 * post: Memory is freed and the number of freed bytes is returned
 *
 */
int FreeMemory(int addr) {
    //TODO move element from alloc to free list
    //TODO if element + size + 1 == next element. merge

    // find element at addres
    Element* addrElem = GetElementAtAddr(&allocList, addr);

    if (addrElem == NULL) {
        return -1;
    }

    // save size for return value
    int size = addrElem->size;
    Element* foundElem = NULL;

    #if prntDb
    printf("\n");
    dbPrintList("preFree", addr, &freeList, NULL);
    #endif

    if (freeList.size <= 1) {
        if (freeList.head != NULL && addrElem->address > freeList.head->address) {
            foundElem = GetLastElement(&freeList);
        }

        ListAddAfter(&freeList, addrElem->address, addrElem->size, foundElem);
        ListRemove(&allocList, &addrElem);
    }
    else if (freeList.size > 1) {
        // check if there is a preseading address
        foundElem = freeList.head;
        Element* next = foundElem->next;

        //! flipping causes other logic to break, but this inserts 1050 after 1052
        while (next != NULL && foundElem->address <= addr) {
            foundElem = next;
            next = foundElem->next;
        }

        if (foundElem == freeList.head && foundElem->address > addr) {
            foundElem = NULL;
        }

        ListAddAfter(&freeList, addrElem->address, addrElem->size, foundElem);
        ListRemove(&allocList, &addrElem);
    }

    // clean up
    Element* step = freeList.head;

    while (step != NULL && step->next != NULL) {
        Element* elem = step;
        Element* next = step->next;
        int count = 0;

        while (elem != NULL && elem->next != NULL && count < freeList.size) {
            if (elem->address + elem->size == next->address) {
                elem->size += next->size;
                ListRemove(&freeList, &next);
                next = elem->next;
            }
            count++;
        }

        step = next;
    }

    #if prntDb
    dbPrintList("postFree", addr, &freeList, foundElem);
    printf("\n");
    #endif


    return size;
}

void printSelectedList(FILE* stream, LinkedList* list) {
    Element* elem = list->head;
    int idx = 0;
    
    if (elem == NULL) {
        fprintf(stream, "  <empty>\n");
        return;
    }

    while (elem != NULL) {
        fprintf(stream, "  %d:  addr:%4d  size: %3d\n", idx, elem->address, elem->size);
        elem = elem->next;
        idx++;
    }
}

Element* GetLastElement(LinkedList* list) {
    Element* elem = list->head;

    while (elem != NULL && elem->next != NULL) {
        elem = elem->next;
    }

    return elem;
}

Element* GetElementAtAddr(LinkedList* list, int addr) {
    if (list == NULL || addr < StartAddress) {
        return NULL;
    }

    Element* elem = list->head;

    while (elem != NULL && elem->address != addr) {
        elem = elem->next;
    }

    return elem;
}
