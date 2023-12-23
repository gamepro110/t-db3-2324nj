#include "memory.h"
#include "linked_list.h"

static const int StartAddress = 1000;

static LinkedList freeList;
static LinkedList allocList;

/* function: ConstructMemory
 * pre: -
 * post: memory administration is constructed
 */
void ConstructMemory(int size) {
    ListAddAfter(&freeList, StartAddress, size, NULL);
}

/* function: DestructMemory
 * pre: -
 * post: memory administration is destructed
 */
void DestructMemory() {
    ListRemoveAll(&allocList);
    ListRemoveAll(&freeList);
}

void printSelectedList(FILE* stream, LinkedList* list) {
    Element* elem = list->head;
    int idx = 0;
    
    if (elem == NULL) {
        fprintf(stream, "  <empty>\n");
        return;
    }

    while (elem != NULL) {
        fprintf(stream, "  %d:  addr:%d  size: %d\n", idx, elem->address, elem->size);
        elem = elem->next;
        idx++;
    }
}

/* function: PrintList
 * pre: -
 * post: if stream is valid, list information is printed to stream and 0 is returned
 *       if stream is NULL, -1 is returned
 */
int PrintList(FILE* stream) {
    if (stream == NULL) {
        return -1;
    }

    fprintf(stream, "FreeList:\n---------\n");
    printSelectedList(stream, &freeList);

    fprintf(stream, "AllocList:\n----------\n");
    printSelectedList(stream, &allocList);

    return -1;
}

/* function: ClaimMemory
 * pre: nrofBytes > 0
 * post: if no memory block of nrofBytes available return -1
 *       otherwise the first block that is large enough is claimed and the start address is returned
 */
int ClaimMemory(int nrofBytes) {
    Element* freeHead = freeList.head;
    while (freeHead != NULL && freeHead->next != NULL) {
        freeHead = freeHead->next;
    }

    if (freeHead->size < nrofBytes) {
        return -1;
    }

    //TODO resize freelist (variable only)
    //TODO update freelist address
    Element* elem = freeList.head;

    elem->address += nrofBytes;
    elem->size -= nrofBytes;

    //TODO make new element for alloc list with original address of freelist and size requested
    Element* allocElem = allocList.head;
    while (allocElem != NULL) {
        allocElem = allocElem->next; // get last elem
    }
    //! debug check if this function is correct
    ListAddAfter(&allocList, StartAddress, nrofBytes, allocElem);

    return 0;
}

/* function: FreeMemory
 * pre: Parameter addr must match the start of an allocatd memory block. Otherwhise return -1.
 * post: Memory is freed and the number of freed bytes is returned
 *
 */
int FreeMemory(int addr) {
    //TODO move element from alloc to free list
    //TODO if element + size + 1 == next element. merge

    (void)addr; //TODO
    return -1;
}
