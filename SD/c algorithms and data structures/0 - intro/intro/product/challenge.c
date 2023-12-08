#include "challenge.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <limits.h> // chatgpt

/*
/// @brief checks if given array contains given number and returns the index if found
/// @param number element to be found
/// @param index first index of the requested number
/// @return -1 on error, 0 on found, 1 on NOT found
///FIXME fails on case: [5, 10, 10, 5]. sets 2 idx with 10
int contains(int arraySize, int array[arraySize], int* lastElem, int number, int* index) {
    if (array == NULL || index == NULL || lastElem == NULL) {
        return -1;
    }

    int idx = 0;
    int returnVal = 1;
    bool done = false;

    while (idx <= arraySize && !done) {
        if (array[idx] == number) {
            done = true;
            returnVal = 0;
            *index = idx;

            if ((*lastElem) < idx) {
                *index += *lastElem - *index;
            }

            if ((*lastElem) > idx) {
                (*lastElem)--; // take 1 off to balace double takes
            }

            (*lastElem)++;
        }

        idx++;
    }

    return returnVal;
}//*/

/// @brief return which numbers have been found and how many in the input array
/// @return -1 on fail, 0 on succes
int CountArray(int inputSize, int inputArray[inputSize], int** outputCount) {
    if (inputArray == NULL || outputCount == NULL) {
        return -1;
    }

    for (int idx = 0; idx < inputSize; idx++) {
        (*outputCount)[idx] = 0;
    }

    for (int idx = 0; idx < inputSize; idx++) {
        int value = inputArray[idx];
        (*outputCount)[value]++;
    }

    return 0;
}

//FIXME
int FindSmallestNumberThatIsRepeatedKTimes(int* array, int size, int k, int* smallestNumber) {
    if (array == NULL || smallestNumber == NULL) {
        return -1;
    }

    int arrSize = 100000;
    int returnVal = 0;
    int smallest = 1000000000;
    int* numCount = calloc(sizeof(int), arrSize);

    if (CountArray(size, array, &numCount)) {
        returnVal = -1;
    }
    else {
        int amountFound = -1;

        for (int idx = 0; idx < size; idx++) {
            amountFound = numCount[idx];

            if (amountFound == k) {
                smallest = idx;
            }
        }
    }

    free(numCount);
    *smallestNumber = smallest;
    return returnVal;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_0(int* array, int size, int k, int* difference) {
    if (array == NULL || difference == NULL) {
        return -1;
    }

    int min_val = 0;
    int max_val = 0;

    // loop through the array from front and back
    // add value to min and max sum when value is not 0

    *difference = max_val - min_val;

    return 0;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_1(int* array, int size, int k, int* difference) {
    return -1;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_2(int* array, int size, int k, int* difference) {
    return -1;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_3(int* array, int size, int k, int* difference) {
    return -1;
}
