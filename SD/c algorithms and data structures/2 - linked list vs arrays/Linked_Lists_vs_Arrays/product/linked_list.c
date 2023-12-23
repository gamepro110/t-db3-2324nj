#include "linked_list.h"

#include <stdlib.h>

// static Element* head = NULL;

/* function: ListAddTail
 * pre: -
 * post: an element is added to the end of the linked list
 * returns: 0 on success, -1 on fail
 */
int ListAddTail(LinkedList* list, int address, int size) {
    if (list == NULL) {
        return -1;
    }

    list->size++;

    if(list->head == NULL) {
        list->head = calloc(1, sizeof(Element));
        list->head->address = address;
        list->head->size = size;
        list->head->next = NULL;
        return 0;
    }

    Element* elem = NULL;
    elem = calloc(1, sizeof(Element));
    elem->address = address;
    elem->size = size;
    elem->next = NULL;

    Element* curElem = list->head;

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
int ListAddAfter(LinkedList* list, int address, int size, Element* element) {
    if (list == NULL) {
        return -1;
    }

    Element* new = calloc(1, sizeof(Element));
    new->address = address;
    new->size = size;

    if (element != NULL) {
        Element* next = element->next;
        new->next = next;
        element->next = new;
    }
    else {
        new->next = list->head;
        list->head = new;
    }

    return 0;
}


/* function: ListGetHead
 * pre: -
 * post: first element in linked list is returned
 * returns: first element on success, NULL if list is empty
 */
Element* ListGetHead(LinkedList* list) {
    if (list == NULL) {
        return NULL;
    }

    return list->head;
}


/* function: ListRemoveTail
 * pre: -
 * post: last element is removed from list
 * returns: 0 on success, -1 on fail
 */
int ListRemoveTail(LinkedList* list) {
    if (list == NULL) {
        return -1;
    }

    Element* current = list->head;
    Element* last = NULL;

    if (current == NULL) {
        return -1;
    }

    while (current->next != NULL) { 
        last = current;
        current = current->next;
    }

    free(current); 

    if (last != NULL) {
        last->next = NULL; 
    }
    else {
        // could not assign last, means list is empty
        list->head = NULL;
    }

    list->size--;
    return 0;
}

/* function: ListRemove
 * pre: -
 * post: element is removed from list, pointer from callee is made NULL
 * returns: 0 on success, -1 on fail
 */
int ListRemove(LinkedList* list, Element** element) {
    if (list == NULL || element == NULL) {
        return -1;
    }

    Element** prev = &list->head;

    // if head != element
    if ((*prev)->address != (*element)->address) {
        while ((*prev)->next != (*element) && (*prev)->next != NULL) {
            (*prev) = (*prev)->next;
        }

        (*prev)->next = (*element)->next;
    }
    else {
        // if head == element
        list->head = (*element)->next;
    }

    free(*element);
    (*element) = NULL;

    list->size--;
    return 0;
}

/* function: ListRemoveAll
 * pre: -
 * post: all existing elements from list are removed
 */
void ListRemoveAll(LinkedList* list) {
    if (list == NULL) {
        //failed to empty list, provided NULL
        return;
    }

    Element* elem = list->head;
    Element* next = elem;

    while (next != NULL) {
        next = elem->next;
        free(elem);
        elem = next;
    }

    list->size = 0;
    list->head = NULL;
}
