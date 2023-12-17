#include "linked_list.h"

#include <stdlib.h>

static Element* head = NULL;

/* function: ListAddTail
 * pre: -
 * post: an element is added to the end of the linked list
 * returns: 0 on success, -1 on fail
 */
int ListAddTail(int address, int size) {
    if(head == NULL) {
        head = calloc(1, sizeof(Element));
        head->address = address;
        head->size = size;
        head->next = NULL;
        return 0;
    }

    Element* elem = NULL;
    elem = calloc(1, sizeof(Element));
    elem->address = address;
    elem->size = size;
    elem->next = NULL;

    Element* curElem = head;

    while (curElem != NULL) {
        if (curElem->next == NULL) {
            break;
        }

        curElem = curElem->next;
    }

    curElem->next = elem;

    return 0;
}

/* function: ListAddAfter
 * pre: -
 * post: a new element with given data is added after element
 *       in the linked list. If element is NULL, the new element
 *       is added to the front of the list.
 * returns: 0 on success, -1 on fail
 */
int ListAddAfter(int address, int size, Element* element) {
    Element* new = calloc(1, sizeof(Element));
    new->address = address;
    new->size = size;

    if (element != NULL) {
        Element* next = element->next;
        new->next = next;

        element->next = new;
    }
    else {
        new->next = head;
        head = new;
    }
    

    return 0;
}


/* function: ListGetHead
 * pre: -
 * post: first element in linked list is returned
 * returns: first element on success, NULL if list is empty
 */
Element* ListGetHead() {
    return head;
}


/* function: ListRemoveTail
 * pre: -
 * post: last element is removed from list
 * returns: 0 on success, -1 on fail
 */
int ListRemoveTail() {
    Element* current = head;
    Element* last = NULL;

    if (head == NULL) {
        return -1;
    }

    while (current->next != NULL) {
        last = current;
        current = current->next;
    }

    free(current);
    last->next = NULL;

    return 0;
}

/* function: ListRemove
 * pre: -
 * post: element is removed from list, pointer from callee is made NULL
 * returns: 0 on success, -1 on fail
 */
int ListRemove(Element** element) {
    if (element == NULL) {
        return -1;
    }

    Element* prev = head;

    while (prev->next != (*element)) {
        prev = prev->next;
    }

    Element* newNext = (*element)->next;
    free(*element);
    (*element) = NULL;

    prev->next = newNext;

    return 0;
}

/* function: ListRemoveAll
 * pre: -
 * post: all existing elements from list are removed
 */
void ListRemoveAll() {
    Element* elem = head;
    Element* next = elem;

    while (next != NULL) {
        next = elem->next;
        free(elem);
        elem = next;
    }

    head = NULL;
}
