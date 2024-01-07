#include "unity.h"

#include "Tree.h"

#include <stdbool.h>

// I rather dislike keeping line numbers updated, so I made my own
// macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void) {
    // This is run before EACH test
}

void tearDown(void) {
    // This is run after EACH test
}

void testTree_CreateTree(void) {
    TEST_ASSERT_FALSE(true);
}


int main(int argc, char* argv[]) {
    if (argc != 1) {
        fprintf(stderr, "%s: argc=%d\n", argv[0], argc);
        return -1;
    }

    UnityBegin();

    MY_RUN_TEST(testTree_CreateTree);

    return UnityEnd();
}
