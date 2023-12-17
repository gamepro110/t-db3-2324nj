#include "unity.h"

#include "linked_list.h"

// I rather dislike keeping line numbers updated, so I made my own
// macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

static LinkedList list;
static const int startAddress = 100;

void setUp(void) {
    // This is run before EACH test
}

void tearDown(void) {
    // This is run after EACH test
    ListRemoveAll(&list);
}

void fillList(int count) {
    for (int i = 0; i < count; i++) {
        ListAddTail(&list, startAddress + (i * 10), 10);
    }
}

void test_ListAddTail(void) {
    for (int i = 1; i < 11; i++) {
        TEST_ASSERT_EQUAL(0, ListAddTail(&list, startAddress + i, 1));
        TEST_ASSERT_EQUAL_MESSAGE(i, list.size, "unexpected size");
    }
}

void test_ListAddTail_null(void) {
    TEST_ASSERT_EQUAL(-1, ListAddTail(NULL, startAddress, 1));
    TEST_ASSERT_EQUAL_MESSAGE(0, list.size, "unexpected size");
}

void test_ListAddAfter(void) {
    fillList(10);

    Element* last = ListGetHead(&list);

    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    TEST_ASSERT_EQUAL(0, ListAddAfter(&list, startAddress, 1, last));
}

void test_ListAddAfter_nullList(void) {
    ListAddTail(&list, startAddress, 10);
    Element* e = list.head;
    TEST_ASSERT_EQUAL(-1, ListAddAfter(NULL, startAddress, 20, e));
}

void test_ListAddAfter_nullElement(void) {
    ListAddTail(&list, startAddress + 100, 10);
    TEST_ASSERT_EQUAL(0, ListAddAfter(&list, startAddress, 20, NULL));
}

void test_ListGetHead() {
    TEST_ASSERT_NULL(ListGetHead(NULL));
    TEST_ASSERT_NULL(ListGetHead(&list));

    ListAddTail(&list, startAddress, 10);

    TEST_ASSERT_NOT_NULL(ListGetHead(&list));
}

void test_ListRemoveTail(void) {
    fillList(10);

    for (int i = 0; i < 10; i++) {
        TEST_ASSERT_EQUAL(0, ListRemoveTail(&list));
        TEST_ASSERT_EQUAL(9 - i, list.size);
    }
}

void test_ListRemove(void) {
    const int count = 10;
    fillList(count);

    TEST_ASSERT_EQUAL(count, list.size);
    Element* elem = ListGetHead(&list);
    TEST_ASSERT_EQUAL(0, ListRemove(&list, &elem));
    TEST_ASSERT_EQUAL(count - 1, list.size);
}

void test_ListRemove_null(void) {
    fillList(10);

    TEST_ASSERT_EQUAL(-1, ListRemove(NULL, &list.head));
    TEST_ASSERT_EQUAL(-1, ListRemove(&list, NULL));
    TEST_ASSERT_EQUAL(-1, ListRemove(NULL, NULL));
}

void test_ListRemoveAll(void) {
    fillList(10);

    ListRemoveAll(NULL);
    TEST_ASSERT_EQUAL(10, list.size);

    ListRemoveAll(&list);
    TEST_ASSERT_EQUAL(0, list.size);
}

int main(int argc, char* argv[]) {
    if (argc != 1) {
        fprintf(stderr, "%s: argc=%d\n", argv[0], argc);
        return -1;
    }

    UnityBegin();

    MY_RUN_TEST(test_ListAddTail);
    MY_RUN_TEST(test_ListAddTail_null);
    MY_RUN_TEST(test_ListAddAfter);
    MY_RUN_TEST(test_ListAddAfter_nullList);
    MY_RUN_TEST(test_ListAddAfter_nullElement);
    MY_RUN_TEST(test_ListGetHead);
    MY_RUN_TEST(test_ListRemoveTail);
    MY_RUN_TEST(test_ListRemove);
    MY_RUN_TEST(test_ListRemove_null);
    MY_RUN_TEST(test_ListRemoveAll);

    return UnityEnd();
}
