#include <string.h>

#include "challenge.h"
#include "unity.h"

#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void) {}

void tearDown(void) {}

void TestFunc_FindSmallestNumberThatIsRepeatedKTimes(int* array, int arraySize, int K, int* smallestNumber, int expect) {
    if (array == NULL || smallestNumber == NULL) {
        printf("null ptr provided in 'TestFunc_FindSmallestNumberThatIsRepeatedKTimes'");
        TEST_FAIL();
    }

    TEST_ASSERT_EQUAL(0, FindSmallestNumberThatIsRepeatedKTimes(
        array,
        arraySize,
        K,
        smallestNumber
    ));

    TEST_ASSERT_EQUAL(expect, *smallestNumber);
}

void test_find_smallest_number_for_number_of_wanted_occurences(void) {
    int array[] = {10,10,2,2,1,1,1,4,5,4};
    int arraySize = sizeof(array)/sizeof(array[0]);
    int K = 2;
    int smallestNumber = 0;

    TestFunc_FindSmallestNumberThatIsRepeatedKTimes(array, arraySize, K, &smallestNumber, 2);

    K = 3;
    TestFunc_FindSmallestNumberThatIsRepeatedKTimes(array, arraySize, K, &smallestNumber, 1);

    K = 1;
    TestFunc_FindSmallestNumberThatIsRepeatedKTimes(array, arraySize, K, &smallestNumber, 5);
}

void TestFunc_ComputeDifferenceBetweenMaxAndMinSumOfKElements_0(int* array, int arraySize, int K, int* difference, int expect) {
    if (array == NULL || difference == NULL) {
        printf("null ptr provided in 'TestFunc_ComputeDifferenceBetweenMaxAndMinSumOfKElements_0'");
        TEST_FAIL();
    }

    TEST_ASSERT_EQUAL(
        0,
        ComputeDifferenceBetweenMaxAndMinSumOfKElements_0(
            array,
            arraySize,
            K,
            difference
        )
    );

    TEST_ASSERT_EQUAL(expect, *difference);
}

void test_part2_example_compute_difference_between_max_and_min_sum_of_k_elements_0(void) {
    int array[] = {2, 4, 6, 7, 2, 4, 5, 6, 3, 6,};
    int arraySize = sizeof(array)/sizeof(array[0]);
    int K = 4;
    int difference = 0;

    TestFunc_ComputeDifferenceBetweenMaxAndMinSumOfKElements_0(
        array,
        arraySize,
        K,
        &difference,
        14
    );
}

void test_compute_difference_between_max_and_min_sum_of_k_elements_0(void) {
    int array[] = {10,10,2,2,1,1,1,4,5,4};
    int arraySize = sizeof(array)/sizeof(array[0]);
    int K = 2;
    int difference = 0;

    TestFunc_ComputeDifferenceBetweenMaxAndMinSumOfKElements_0(array, arraySize, K, &difference, 7);

    K = 3;
    TestFunc_ComputeDifferenceBetweenMaxAndMinSumOfKElements_0(array, arraySize, K, &difference, 10);

    K = 1;
    TestFunc_ComputeDifferenceBetweenMaxAndMinSumOfKElements_0(array, arraySize, K, &difference, 4);
}

int main (int argc, char * argv[])
{
    UnityBegin();

    MY_RUN_TEST(test_find_smallest_number_for_number_of_wanted_occurences);
    MY_RUN_TEST(test_part2_example_compute_difference_between_max_and_min_sum_of_k_elements_0);
    MY_RUN_TEST(test_compute_difference_between_max_and_min_sum_of_k_elements_0);

    return UnityEnd();
}
