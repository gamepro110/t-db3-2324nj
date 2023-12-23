#include "memory.h"
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

    if (freeHead->size < nrofBytes) {
        return -1;
    }

    //tODO resize freelist (variable only)
    //tODO update freelist address
    Element* elem = freeList.head;

    elem->address += nrofBytes;
    elem->size -= nrofBytes;

    //tODO make new element for alloc list with original address of freelist and size requested
    Element* allocElem = GetLastElement(&allocList);

    int newAddr = (allocElem == NULL) ? StartAddress : (allocElem->address + allocElem->size);
    ListAddAfter(&allocList, newAddr, nrofBytes, allocElem);

    return newAddr;
}

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

    // check if there is a preseading address
    Element* prevAddr = freeList.head;

    //TODO check why 1050 gets inserted before 1000
    // probably related to the if on :103

    bool prevNotNull = prevAddr != NULL;
    bool prevNextNotNull = prevAddr->next != NULL;
    bool nextAddrGreaterThanAddr = (prevNextNotNull && prevAddr->next->address <= addr);

    while (prevNotNull && prevNextNotNull && nextAddrGreaterThanAddr) {
        prevAddr = prevAddr->next;

        prevNotNull = prevAddr != NULL;
        prevNextNotNull = prevAddr->next != NULL;
        nextAddrGreaterThanAddr = (prevNextNotNull && prevAddr->next->address >= addr);
    }

    if (prevAddr == freeList.head) {
        prevAddr = NULL;
    }

    ListAddAfter(&freeList, addrElem->address, addrElem->size, prevAddr);
    ListRemove(&allocList, &addrElem);

    // clean up
    Element* elem = freeList.head;
    Element* next = elem->next;

    while (elem != NULL && elem->next != NULL) {
        if (elem->address + elem->size == next->address) {
            elem->size += next->size;
            ListRemove(&freeList, &next);
        }

        elem = elem->next;
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
