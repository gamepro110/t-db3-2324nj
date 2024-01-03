#include "my_memory.h"
#include "linked_list.h"

#include <stdbool.h>

static const int StartAddress = 1000;
static int startSize = 0;

static LinkedList freeList;
static LinkedList allocList;

void ConstructMemory(int size) {
    startSize = size;
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

    if (freeHead == NULL || freeHead->size < nrofBytes || nrofBytes < 1) {
        return -1;
    }

    //tODO resize freelist (variable only)
    //tODO update freelist address
    Element* elem = freeList.head;
    int newAddr = 0;

    if (elem == NULL) {
        return -1;
    }

    elem->address += nrofBytes;
    elem->size -= nrofBytes;

    //tODO make new element for alloc list with original address of freelist and size requested
    Element* allocElem = allocList.head;

    if (allocElem == NULL) {
        newAddr = StartAddress;
    }
    else {
        if (allocElem->address - StartAddress >= nrofBytes) {
            allocElem = NULL;
            newAddr = StartAddress;
        }
        else {
            int sizeBetween = 0;
            if (allocList.size > 1) {
                while (allocElem != NULL && allocElem->next != NULL && sizeBetween <= nrofBytes) {
                    sizeBetween = allocElem->next->address - (allocElem->address + allocElem->size);
                    allocElem = allocElem->next;
                }

                if (allocElem->next != NULL && sizeBetween >= nrofBytes) {
                    allocElem = allocElem->next;
                    // printf("________________________________________________\n");
                }
            }

            newAddr = allocElem->address + allocElem->size;
        }

        if (newAddr >= StartAddress + startSize) {
            // printf("<<<<OUT OF BOUND.>>>>\n");
            return -1; // should never hit
        }
    }

    ListAddAfter(&allocList, newAddr, nrofBytes, allocElem);

    if (freeHead->size == 0) {
        ListRemoveTail(&freeList);
    }

    return newAddr;
}

void dbPrintList(const char* listName, LinkedList* list, Element* lastFound) {
    printf("%s", listName);
    
    if (lastFound == NULL) {
        printf("%s ", "(last NILL)");
    }
    else {
        printf("(last % 2d|% 2d) ", lastFound->address, lastFound->size);
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


    if (freeList.size <= 1) {
        if (freeList.head != NULL && addrElem->address > freeList.head->address) {
            foundElem = GetLastElement(&freeList);
        }
    }
    else if (freeList.size > 1) {
        // check if there is a preseading address
        foundElem = freeList.head;
        Element* prev = NULL;

        #if prntDb
        dbPrintList("preFree ", &freeList, foundElem);
        #endif

        while (foundElem->next != NULL && foundElem->address < addr) {
            prev = foundElem;
            foundElem = foundElem->next;
        }

        foundElem = prev;

        #if prntDb
        dbPrintList("postFree", &freeList, foundElem);
        #endif

    }

    ListAddAfter(&freeList, addrElem->address, addrElem->size, foundElem);
    ListRemove(&allocList, &addrElem);

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
