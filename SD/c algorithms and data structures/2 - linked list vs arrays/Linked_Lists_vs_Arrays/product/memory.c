#include "memory.h"
#include "linked_list.h"

static const int StartAddress = 1000;

static LinkedList freeList;
static LinkedList AllocList;

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
    ListRemoveAll(&AllocList);
    ListRemoveAll(&freeList);
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

    //TODO call func that prints list on both free and alloc + check format from output example

    return -1;
}

/* function: ClaimMemory
 * pre: nrofBytes > 0
 * post: if no memory block of nrofBytes available return -1
 *       otherwise the first block that is large enough is claimed and the start address is returned
 */
int ClaimMemory(int nrofBytes) {
    //TODO resize freelist (variable only)
    //TODO update freelist address
    //TODO make new element for alloc list with original address of freelist and size requested

    (void)nrofBytes; //TODO
    return -1;
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
