#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "mystack.h"
#include "unity.h"


// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

typedef struct data_t Data;
struct data_t{
    int num;
    int v;
    float d;
};

void setUp() {
}

void tearDown() {
}

void test_create_destroy_stack(void) {
    const int arrSize = 10;
    int arr[arrSize];
    int arrIdx = 0;

    for (int i = 1; i <= arrSize; i++) {
        arr[arrIdx] = MystackCreate(sizeof(Data));
        TEST_ASSERT_TRUE(arr[arrIdx] > 0);
        TEST_ASSERT_TRUE(arr[arrIdx] == i);
        arrIdx++;
    }

    for (int i = 1; i <= arrSize; i++) {
        TEST_ASSERT_EQUAL(0, MystackDestroy(i));
    }
}

void test_push_elem(void) {
    const int arrSize = 10;

    for (int i = 1; i <= arrSize; i++) {
        int handle = MystackCreate(sizeof(Data));

        for (int j = 1; j <= arrSize; j++) {
            Data* d = calloc(1, sizeof(Data));
            d->num = j;
            d->v = j*j;
            d->d = j*j*j;
            TEST_ASSERT_EQUAL(0, MystackPush(handle, d));
        }
    }


    for (int i = 1; i <= arrSize; i++) {
        MystackDestroy(i);
    }
}

void test_pop_elem(void) {
    const int arrSize = 10;

    for (int i = 1; i <= arrSize; i++) {
        int handle = MystackCreate(sizeof(Data));

        for (int j = 1; j <= arrSize; j++) {
            Data* d = calloc(1, sizeof(Data));
            d->num = j;
            d->v = j*j;
            d->d = j*j*j;
            TEST_ASSERT_EQUAL(0, MystackPush(handle, d));
        }
        
        for (int j = arrSize; j > 0; j--) {
            Data data;
            TEST_ASSERT_EQUAL(0, MystackPop(i, &data));
            TEST_ASSERT_EQUAL(j, data.num);
            TEST_ASSERT_EQUAL(j*j, data.v);
            TEST_ASSERT_EQUAL(j*j*j, data.d);
        }
    }


    for (int i = 1; i <= arrSize; i++) {
        MystackDestroy(i);
    }
}

int main() {
    UnityBegin();

    MY_RUN_TEST(test_create_destroy_stack);
    MY_RUN_TEST(test_push_elem);
    MY_RUN_TEST(test_pop_elem);

    return UnityEnd();
}
