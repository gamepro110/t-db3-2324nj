#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

/// @brief gets array size
/// @return -1 on error, 0 on succes
int parseArrSize(int* sizePtr);

/// @brief parses stdin and fills the array
/// @return -1 on error, 0 on succes
int parseArrContent(int* sizePtr, int** arrayPtr);

/// @brief parses stdin and populates arrayK
/// @return -1 on error, 0 on succes
int parseArrK(int* arrayK);

int parse(int* sizePtr, int** arrayPtr, int* arrayK) {
    if (sizePtr == NULL || arrayPtr == NULL || arrayK == NULL) {
        return -1;
    }

    parseArrSize(sizePtr);

    // make array with correct size
    (*arrayPtr) = (int*)calloc(sizeof(int), *sizePtr);

    if ((*arrayPtr) == NULL) {
        printf("failed to create array\n");
        return -1;
    }

    parseArrContent(sizePtr, arrayPtr);
    parseArrK(arrayK);

    return 0;
}

int parseArrSize(int* sizePtr) {
    if (sizePtr == NULL) {
        return -1;
    }

    int size = 0;

    if (scanf("%d", &size) < 1) {
        printf("failed to parse arraySize\n");
    }

    *sizePtr = size;
    return 0;
}

int parseArrContent(int* sizePtr, int** arrayPtr) {
    if (sizePtr == NULL || arrayPtr == NULL) {
        return -1;
    }

    int value = 0;
    int scanVal = 0;
    int arrIdx = 0;

    while (arrIdx < (*sizePtr) && scanf("%d%n", &value, &scanVal) == 1) {
        (*arrayPtr)[arrIdx] = value;
        arrIdx++;
    }

    return 0;
}

int parseArrK(int* arrayK) {
    if (arrayK == NULL) {
        return -1;
    }

    int k = 0;

    if (scanf("%d", &k) < 1) {
        printf("failed to parse arrayK\n");
    }

    *arrayK = k;
    return 0;
}
