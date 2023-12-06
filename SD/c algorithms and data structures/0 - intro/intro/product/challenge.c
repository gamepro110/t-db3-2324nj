#include "challenge.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//*
/// @brief checks if given array contains given number and returns the index if found
/// @param number element to be found
/// @param index first index of the requested number
/// @return -1 on error, 0 on found, 1 on NOT found
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
int CountArray(int inputSize, int inputArray[inputSize], int** outputCount, int** outputNumber) {
    if (inputArray == NULL || outputCount == NULL || outputNumber == NULL) {
        return -1;
    }

    for (int idx = 0; idx < inputSize; idx++) {
        (*outputCount)[idx] = 0;
        (*outputNumber)[idx] = 0;
    }

    int wIdx = 0;
    int value = 0;
    int containsVal = 0;
    int lastElem = 0;

    for (int rIdx = 0; rIdx < inputSize; rIdx++) {
        value = inputArray[rIdx];
        containsVal = contains(inputSize, inputArray, &lastElem, value, &wIdx);

        if (containsVal != 0) {
            printf("contains check fail");
            return -1;
        }
        else {
            (*outputNumber)[wIdx] = value;
            (*outputCount)[wIdx]++;
        }
    }

    return 0;
}

int FindSmallestNumberThatIsRepeatedKTimes(int* array, int size, int k, int* smallestNumber) {
    if (array == NULL || smallestNumber == NULL) {
        return -1;
    }

    int returnVal = 0;
    long smallest = 10000000000000;
    int* numCount = calloc(sizeof(int), size);
    int* numIdx = calloc(sizeof(int), size);

    // printf("\nfinding K(%d) \n", k);

    if (CountArray(size, array, &numCount, &numIdx)) {
        returnVal = -1;
    }
    else {
        int amountFound = -1;

        for (int idx = 0; idx < size; idx++) {
            amountFound = numCount[idx];

            if (amountFound == k) {
                int num = numIdx[idx];

                // fprintf(stderr, "\n");
                // for (int i = 0; i < size; i++) {
                //     fprintf(stderr, "%d: %d\n", numIdx[i], numCount[i]);
                // }
                // fprintf(stderr, "\n");

                if (num < smallest) {
                    smallest = num;
                }
            }
        }
    }

    free(numIdx);
    free(numCount);
    *smallestNumber = smallest;
    return returnVal;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_0(int* array, int size, int k, int* difference) {
    if (array == NULL || difference == NULL) {
        return -1;
    }

    int* numCount = calloc(sizeof(int), size);
    int* numIdx = calloc(sizeof(int), size);
    int largest = 0;
    int smallest = 1000000;

    if (CountArray(size, array, &numCount, &numIdx)) {
        printf("failed to count array elements");
        return -1;
    }

    for (int i = 0; i < size; i++) {
        int value = array[i];
        
        smallest = (value < smallest) ? value : smallest;
        largest = (value > largest) ? value : largest;
    }

    free(numIdx);
    free(numCount);
    *difference = (largest - smallest);
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
