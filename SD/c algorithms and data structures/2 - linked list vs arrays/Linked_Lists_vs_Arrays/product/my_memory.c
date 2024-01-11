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
    if (freeList.head == NULL || nrofBytes < 1) {
        return -1;
    }

    Element* freeElem = freeList.head;
    bool spaceAvailable = false;

    if (freeList.size > 1) {
        while (freeElem != NULL && freeElem->next != NULL && spaceAvailable == false) {
            spaceAvailable = freeElem->size >= nrofBytes;

            if (!spaceAvailable) {
                freeElem = freeElem->next;
            }
        }

        if (freeElem->next == NULL) {
            spaceAvailable = freeElem->size >= nrofBytes;
        }

        if (!spaceAvailable) {
            return -1;
        }
    }
    else {
        if (nrofBytes > freeElem->size) {
            return -1;
        }
    }

    int newAddr = freeElem->address;
    freeElem->address += nrofBytes;
    freeElem->size -= nrofBytes;

    if (freeElem->size == 0) {
        ListRemove(&freeList, &freeElem);
    }

    Element* allocElem = allocList.head;

    if (allocElem != NULL) {
        if (allocElem->address - StartAddress >= nrofBytes) {
            allocElem = NULL;
        }
        else {
            if (allocList.size > 1) {
                int sizeBetween = 0;

                while (allocElem != NULL && allocElem->next != NULL && sizeBetween < nrofBytes) {
                    sizeBetween = allocElem->next->address - (allocElem->address + allocElem->size);

                    if (sizeBetween < nrofBytes) {
                        allocElem = allocElem->next;
                    }
                }
            }
        }

        if (newAddr >= StartAddress + startSize) {
            return -1; // should never hit
        }
    }

    ListAddAfter(&allocList, newAddr, nrofBytes, allocElem);

    return newAddr;
}

/* function: FreeMemory
 * pre: Parameter addr must match the start of an allocatd memory block. Otherwhise return -1.
 * post: Memory is freed and the number of freed bytes is returned
 *
 */
int FreeMemory(int addr) {
    //TODO check order of free, simple <1020 -> 1000 -> 1052>...
    Element* addrElem = GetElementAtAddr(&allocList, addr);

    if (addrElem == NULL) {
        return -1;
    }

    // save size for return value
    const int size = addrElem->size;
    Element* foundElem = NULL;

    if (freeList.size == 1) {
        if (addrElem->address > freeList.head->address) {
            foundElem = freeList.head;
        }
    }
    else if (freeList.size > 1) {
        foundElem = freeList.head;

        if (addr < foundElem->address) {
            foundElem = NULL;
        }
        else if (addr == foundElem->address) {
            // doubt this will get hit...
            printf("_________________________________________________________________________________\n");
        }
        else {
            Element* prev = NULL;
            while (foundElem->address < addr && foundElem->next !=  NULL) {
                prev = foundElem;
                foundElem = foundElem->next;
            }

            if (prev != NULL && foundElem->address > addr) {
                foundElem = prev;
            }
        }
    }

    ListAddAfter(&freeList, addrElem->address, addrElem->size, foundElem);
    ListRemove(&allocList, &addrElem);

    Element* elem = freeList.head;
    Element* next = elem->next;

    while (freeList.size > 1 && elem->next != NULL) {
        if (elem->address + elem->size == next->address) {
            elem->size += next->size;
            ListRemove(&freeList, &next);
        }
        else {
            elem = elem->next;
        }
        next = elem->next;
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
        fprintf(stream, "% 3d:  addr:%4d  size: %3d\n", idx, elem->address, elem->size);
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
