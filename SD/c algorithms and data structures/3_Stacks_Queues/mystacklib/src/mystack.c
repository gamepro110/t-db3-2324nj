#include "mystack.h"
#include "logging.h"

#include <stdlib.h>

/* The stack is an abstract data type.
 * this means that the internal structures are
 * never exposed to the users of the library.
 */

/* Note: the stacks have no knowledge of what types
 * they are storing. This is not a concern of the stack
 */

typedef struct stackObject {
	void* obj;
	struct stackObject* next;
} StackObject_t;

// "list" of stack roots.
typedef struct stackMeta {
	StackObject_t* stack;
	size_t objsize;
	int numelem;
	int handle;
	struct stackMeta* next;
} StackMeta_t;

StackMeta_t* gStackList = NULL;

StackMeta_t* FindList(int handle);
StackObject_t* ctorStackObj();
int PeekStack(StackMeta_t* inList, StackObject_t** elem, StackObject_t* previous);
int FreeStackElem(StackObject_t** item);

int MystackCreate(size_t objsize) {
    if (objsize < 1) {
        return -1;
    } /* Hint: use gStackList */
    int handle = 1;
    StackMeta_t* list = gStackList;

    if (list == NULL) {
        gStackList = malloc(sizeof(StackMeta_t));
        list = gStackList;
    }
    else {
        StackMeta_t* item = gStackList;
        StackMeta_t* prev = gStackList;

        while (item != NULL && item->next != NULL) {
            prev = item;
            item = item->next;
        }

        handle = prev->handle + 1;
        list = item;
    }

    list->objsize = objsize;
    list->handle = handle;
    list->numelem = 0;

    DBG_PRINTF("Created stack with handle: %d and objsize %zu bytes\n", handle, objsize);
    return handle;
}

int MystackPush(int handle, void* obj) {
    if (obj == NULL) {
        return -1;
    }

    StackMeta_t* list = FindList(handle);

    if (list == NULL) {
        return -1;
    }

    StackObject_t* new = ctorStackObj();
    new->obj = obj;

    if (list->numelem > 0) {
        StackObject_t* stackObj = list->stack;

        while (stackObj != NULL && stackObj->next != NULL) {
            stackObj = stackObj->next;
        }

        stackObj->next = new;
    }
    else {
        list->stack = new;
    }

    list->numelem++;

    DBG_PRINTF("handle: %d\n, obj: %p\n", handle, obj); 	
    return 0;
}

int MystackPop(int handle, void* obj) {
    if (obj == NULL) {
        return -1;
    }

    StackMeta_t* list = FindList(handle);
    StackObject_t* elem;
    StackObject_t prev;

    if (list == NULL || PeekStack(list, &elem, &prev) == -1) {
        return -1;
    }

    prev.next = NULL; //break link to elem to be freed
    obj = elem->obj; // returned the obj
    list->numelem--;

    FreeStackElem(&elem); // free elem

    DBG_PRINTF("handle: %d\n, obj: %p\n", handle, obj); 	
    return 0;
}

int MystackDestroy(int handle) {
    StackMeta_t* list = FindList(handle);

    if (list == NULL) {
        return -1;
    }

    //TODO destroy all nodes
    StackObject_t* item = list->stack;
    StackObject_t* freeItem = NULL;

    while (item != NULL) {
        freeItem = item;
        if (FreeStackElem(&freeItem) == -1) {
            printf("failed to clean up item\a\n");
        }
        item = item->next;
    }

    //TODO destroy list from `gStackList`

    StackMeta_t* prevList = gStackList;

    while (prevList != NULL && prevList->next != NULL && prevList->next != list) {
        prevList = prevList->next;
    }

    prevList->next = list->next;

    for (int i = 0; i < list->numelem; i++) {
        StackObject_t* item;
        PeekStack(list, &item, NULL);
    }

    free(list);
    list = NULL;

    DBG_PRINTF("handle: %d\n", handle); 	
    return 0;
}

int MystackNofElem(int handle) {
    StackMeta_t* list = FindList(handle);

    if (list == NULL) {
        return -1;
    }

    DBG_PRINTF("handle: %d\n", handle);
    return list->numelem;
}

StackMeta_t* FindList(int handle) {
    StackMeta_t* item = gStackList;

    while (item != NULL && item->handle != handle) {
        item = item->next;
    }

    return item;
}

StackObject_t* ctorStackObj() {
    StackObject_t* newObj = malloc(sizeof(StackObject_t));
    newObj->next = NULL;
    newObj->obj = NULL;
    return newObj;
}

typedef struct data Data;

/// @brief gets last element from the stack
/// @param inList input list
/// @param elem ptr to element
/// @param previous element
/// @return -1 on error. 0 on succes
int PeekStack(StackMeta_t* inList, StackObject_t** elem, StackObject_t* previous) {
    if (inList == NULL || elem == NULL || previous == NULL) {
        return -1;
    }

    StackObject_t* stackObj = inList->stack;
    StackObject_t* prev = NULL;

    // the loop below throws a segfault.
    // check
    // - stack::pop
    // - stack::peek

    while (stackObj != NULL && stackObj->next != NULL) {
        prev = stackObj;
        stackObj = stackObj->next;
    }

    (*elem) = stackObj;
    previous = prev;

    return 0;
}

int FreeStackElem(StackObject_t** item) {
    if (item == NULL) {
        return -1;
    }

    free((*item)->obj);
    (*item)->obj = NULL;

    free((*item));
    (*item) = NULL;
    item = NULL;

    return 0;
}
