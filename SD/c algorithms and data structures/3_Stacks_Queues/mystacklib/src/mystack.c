#include "mystack.h"
#include "logging.h"

#include <stdlib.h>
#include <string.h>

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

int StackListRemoveTail(StackMeta_t* list, void* returnObj);
int StackListAddTail(StackMeta_t* list, void* data);

StackMeta_t* FindList(int handle);
StackObject_t* ctorStackObj();
int PeekStack(StackMeta_t* inList, StackObject_t** elem, StackObject_t** previous);
int FreeStackElem(StackObject_t** item);

int MystackCreate(size_t objsize) {
    if (objsize < 1) {
        return -1;
    } /* Hint: use gStackList */
    int handle = 1;
    StackMeta_t* list = gStackList;
    StackMeta_t* newStack = malloc(sizeof(StackMeta_t));

    if (list == NULL) {
        list = gStackList = newStack;
    }
    else {
        StackMeta_t* item = gStackList;
        StackMeta_t* prev = gStackList;

        while (item != NULL) {
            prev = item;
            item = item->next;
        }

        handle = prev->handle + 1;
        prev->next = newStack;
        list = prev->next;
    }

    list->handle = handle;
    list->stack = NULL;
    list->next = NULL;//
    list->objsize = objsize;
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

    if (StackListAddTail(list, obj) == -1) {
        return -1;
    }

    DBG_PRINTF("handle: %d\n, obj: %p\n", handle, obj); 	
    return 0;
}

int MystackPop(int handle, void* obj) {
    StackMeta_t* list = FindList(handle);
    StackObject_t* elem;
    StackObject_t* prev;

    if (list == NULL || PeekStack(list, &elem, &prev) == -1) {
        return -1;
    }

    StackListRemoveTail(list, obj);

    if (prev != NULL) {
        prev->next = NULL; //break link to elem to be freed
    }

    DBG_PRINTF("handle: %d\n, obj: %p\n", handle, obj); 	
    return 0;
}

int MystackDestroy(int handle) {
    StackMeta_t* list = FindList(handle);

    if (list == NULL) {
        return -1;
    }

    while (list->numelem > 0) {
        MystackPop(handle, NULL);
    }

    //TODO destroy list from `gStackList`
    StackMeta_t* prevList = gStackList;

    if (prevList->handle != handle) {
        while (prevList != NULL && prevList->next != NULL && prevList->next->handle != handle) {
            prevList = prevList->next;
        }

        prevList->next = list->next;
    }
    else {
        gStackList = list->next;
    }

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
int PeekStack(StackMeta_t* inList, StackObject_t** elem, StackObject_t** previous) {
    if (inList == NULL || elem == NULL || previous == NULL) {
        return -1;
    }

    StackObject_t* stackObj = inList->stack;
    StackObject_t* prev = NULL;

    while (stackObj != NULL && stackObj->next != NULL) {
        prev = stackObj;
        stackObj = stackObj->next;
    }

    (*elem) = stackObj;
    (*previous) = prev;

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

/* function: StackListRemoveTail
 * pre: -
 * post: last element is removed from list
 * returns: 0 on success, -1 on fail
 */
int StackListRemoveTail(StackMeta_t* list, void* returnObj) {
    if (list == NULL) {
        return -1;
    }

    StackObject_t* current = list->stack;
    StackObject_t* last = NULL;

    if (current == NULL) {
        return -1;
    }

    while (current->next != NULL) { 
        last = current;
        current = current->next;
    }

    // (*returnObj) = current->obj;
    if (returnObj != NULL) {
        memcpy(returnObj, current->obj, list->objsize);
    }

    free(current->obj);
    current->obj = NULL;
    free(current);
    current = NULL;

    if (last != NULL) {
        last->next = NULL; 
    }
    else {
        // could not assign last, means list is empty
        list->stack = NULL;
    }

    list->numelem--;
    return 0;
}

/* function: StackListAddTail
 * pre: -
 * post: an element is added to the end of the linked list
 * returns: 0 on success, -1 on fail
 */
int StackListAddTail(StackMeta_t* list, void* data) {
    if (list == NULL) {
        return -1;
    }

    list->numelem++;

    if(list->stack == NULL) {
        list->stack = calloc(1, sizeof(StackObject_t));
        list->stack->obj = data;
        list->stack->next = NULL;
        return 0;
    }

    StackObject_t* elem = NULL;
    elem = calloc(1, sizeof(StackObject_t));
    elem->next = NULL;
    elem->obj = data;

    StackObject_t* curElem = list->stack;

    while (curElem != NULL) {
        if (curElem->next == NULL) {
            break;
        }

        curElem = curElem->next;
    }

    curElem->next = elem;
    return 0;
}
