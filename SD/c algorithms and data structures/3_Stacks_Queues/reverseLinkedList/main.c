#include <stdio.h>
#include <stdlib.h>

#include "mystack.h"
#include "linked_list.h"

const int listLength = 1500;

typedef struct data_t Data;
struct data_t{
    int data;
};

void printElem(Element* elem) {
    if (elem == NULL) {
        return;
    }

    printf("%d _ ", elem->data);
}

void printList(Element* head) {
    if (head == NULL) {
        return;
    }

    while (head != NULL) {
        printElem(head);
        head = head->next;
    }
}

void printListState(const char* text) {
    printf("--------------------------------------------------------------------\n");
    printf("%s", text);
    printList(ListGetHead());
    printf("\n--------------------------------------------------------------------\n");
}

int main(void) {
    for (int i = 0; i < listLength; i++) {
        if (ListAddTail(i) == -1) {
            break;
        }
    }

    printListState("initial state\n");
    int stackHandle = MystackCreate(sizeof(Data));

    Element* listElem = ListGetHead();
    while (listElem != NULL) {
        Data* d = calloc(1, sizeof(Data));
        d->data = listElem->data;
        MystackPush(stackHandle, d);
        listElem = listElem->next;
    }

    printf("clearing original list\n");
    ListRemoveAll();

    while (MystackNofElem(stackHandle) > 0) {
        Data d;
        MystackPop(stackHandle, &d);
        ListAddTail(d.data);
    }

    printListState("reversed list\n");

    ListRemoveAll();
    MystackDestroy(stackHandle);
    return 0;
}