#include "unity.h"

#include "my_memory.h"

// I rather dislike keeping line numbers updated, so I made my own
// macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void) {
    // This is run before EACH test
    ConstructMemory(100);
}

void tearDown(void) {
    // This is run after EACH test
    DestructMemory();
}

void test_memory_claim(void) {
    TEST_FAIL_MESSAGE("unimplemented");
}

void test_memory_claim_invalid(void) {
    TEST_FAIL_MESSAGE("unimplemented");
}

void test_memory_print(void) {
    TEST_FAIL_MESSAGE("unimplemented");
}

void test_memory_free(void) {
    TEST_FAIL_MESSAGE("unimplemented");
}

void test_memory_free_invalid(void) {
    TEST_FAIL_MESSAGE("unimplemented");
}

int main(int argc, char* argv[]) {
    if (argc != 1) {
        fprintf(stderr, "%s: argc=%d\n", argv[0], argc);
        return -1;
    }

    UnityBegin();

    MY_RUN_TEST(test_memory_claim);
    MY_RUN_TEST(test_memory_claim_invalid);
    MY_RUN_TEST(test_memory_print);
    MY_RUN_TEST(test_memory_free);
    MY_RUN_TEST(test_memory_free_invalid);

    return UnityEnd();
}
