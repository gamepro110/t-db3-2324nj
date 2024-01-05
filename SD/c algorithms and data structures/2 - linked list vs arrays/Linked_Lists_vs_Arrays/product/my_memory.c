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

void dbPrintElement(Element* elem) {
    if (elem == NULL) {
        printf("{%8s}", "<NULL>");
    }
    else {
        printf("{% 3d;% 2d}", elem->address, elem->size);
    }
}
void dbPrintList(LinkedList* list) {
    Element* elem = list->head;

    while (elem != NULL)
    {
        dbPrintElement(elem);

        if (elem->next != NULL) {
            printf(", ");
        }

        elem = elem->next;
    }
    
}
void dbPrint(const char* note, Element* del, Element *element) {
    printf("%s del node: ", note);
    dbPrintElement(del);
    printf("__ elem: ");
    dbPrintElement(element);
    printf("\nfl: ");
    dbPrintList(&freeList);
    printf("\nal: ");
    dbPrintList(&allocList);
    printf("\n");

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
            spaceAvailable = freeElem->next->address - (freeElem->address + freeElem->size) >= nrofBytes;

            if (!spaceAvailable) { // dont move ptr when there is space
                freeElem = freeElem->next;
            }
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
    Element* allocElem = allocList.head;

    if (allocElem != NULL) {
        if (allocElem->address - StartAddress >= nrofBytes) {
            allocElem = NULL;
        }
        else { // checked preseading addrs?
            int sizeBetween = 0;
            if (allocList.size > 1) {
                while (allocElem != NULL && allocElem->next != NULL && sizeBetween <= nrofBytes) {
                    sizeBetween = allocElem->next->address - (allocElem->address + allocElem->size);
                    allocElem = allocElem->next;
                }

                if (allocElem->next != NULL && sizeBetween >= nrofBytes) {
                    allocElem = allocElem->next;
                }
            }
        }

        if (newAddr >= StartAddress + startSize) {
            return -1; // should never hit
        }
    }

    ListAddAfter(&allocList, newAddr, nrofBytes, allocElem);

    if (freeElem->size == 0) {
        ListRemove(&freeList, &freeElem);
    }

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

    if (freeList.size == 1 && addrElem->address > freeList.head->address) {
        foundElem = freeList.head;
    }
    else if (freeList.size > 1) {
        foundElem = freeList.head;
        int sumAddrSize = foundElem->address + foundElem->size;

        if (sumAddrSize >= addr) {
            Element* prev = NULL;

            while (foundElem->next != NULL && foundElem->address < addr) {
                prev = foundElem;
                foundElem = foundElem->next;
            }

            if (prev != NULL) {
                foundElem = prev;
            }
        }
        else if (sumAddrSize <= addr) {
            foundElem = GetLastElement(&freeList);
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
            next = elem->next;
        }
        else {
            elem = elem->next;
        }
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
