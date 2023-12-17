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
    (void)size; //TODO
    (void)StartAddress; //TODO

    (void)freeList;
    (void)AllocList;

    ListAddAfter(freeList, StartAddress, size, NULL);
}

/* function: DestructMemory
 * pre: -
 * post: memory administration is destructed
 */
void DestructMemory() {
    ListRemoveAll(AllocList);
    ListRemoveAll(freeList);
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
    return -1;
}

/* function: ClaimMemory
 * pre: nrofBytes > 0
 * post: if no memory block of nrofBytes available return -1
 *       otherwise the first block that is large enough is claimed and the start address is returned
 */
int ClaimMemory(int nrofBytes) {
    (void)nrofBytes; //TODO
    return -1;
}

/* function: FreeMemory
 * pre: Parameter addr must match the start of an allocatd memory block. Otherwhise return -1.
 * post: Memory is freed and the number of freed bytes is returned
 *
 */
int FreeMemory(int addr) {
    (void)addr; //TODO
    return -1;
}
