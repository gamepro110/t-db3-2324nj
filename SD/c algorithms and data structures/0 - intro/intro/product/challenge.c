#include "challenge.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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

            if (amountFound == k && idx < smallest) {
                smallest = idx;
            }
        }
    }

    free(numCount);
    *smallestNumber = smallest;
    return returnVal;
}

int CalcValue(int* count, int k, int value, int idx, int* out_val) {
    if (count == NULL || out_val == NULL) {
        printf("[CalcValue()] invalid pointer provided");
        return -1;
    }

    if ((*count) < k && value) {
        for (int i = 0; i < value && (*count) < k; i++) {
            (*count)++;
            (*out_val) += idx;
        }
    }

    return 0;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_0(int* array, int size, int k, int* difference) {
    if (array == NULL || difference == NULL) {
        return -1;
    }

    const int maxValue = 10000;
    int* countedArray = calloc(sizeof(int), maxValue);

    if (CountArray(size, array, &countedArray)) {
        printf("faild to count array");
        return -1;
    }

    int minTotalValue = 0;
    int maxTotalValue = 0;

    int itemsAddedToMin = 0;
    int itemsAddedToMax = 0;
    int idx = 0;
    int valueMin = 0;
    int valueMax = 0;
    int reverseIdx = 0;

    while ((itemsAddedToMin < k || itemsAddedToMax < k) && idx < maxValue) { //TODO debug through to check why wrong values are being added
        valueMin = countedArray[idx];
        reverseIdx = (maxValue - 1) - idx;
        valueMax = countedArray[reverseIdx];

        if (CalcValue(&itemsAddedToMin, k, valueMin, idx, &minTotalValue)) {
            return -1;
        }
        if (CalcValue(&itemsAddedToMax, k, valueMax, reverseIdx, &maxTotalValue)) {
            return -1;
        }

        idx++;
    }

    free(countedArray);
    *difference = maxTotalValue - minTotalValue;
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
