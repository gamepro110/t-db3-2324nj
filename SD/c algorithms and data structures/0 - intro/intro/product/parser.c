#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool CheckSubStrNull(const char* sub) {
    return sub == NULL;
}

/// @return -1 on error
bool GetLineFromFile(char* fileText, int fileContentSize, FILE* file) {
    if (fileText == NULL || file == NULL) {
        return NULL;
    }

    char* OutStr = fgets(fileText, fileContentSize, file);

    return CheckSubStrNull(OutStr) && OutStr == fileText;
}

/// @return -1 on error. 0 on succes
int ParseSingleNr(char* fileText, const int fileContentSize, FILE* file, int* sizePtr) {
    if (fileText == NULL || file == NULL) {
        return -1;
    }

    if (GetLineFromFile(fileText, fileContentSize, file)) {
        printf("failed to fetch arraySize str\n");
        return -1;
    }

    (*sizePtr) = atoi(fileText);
    return 0;
}


/// @return -1 on error. 0 on succes
int ParseArrayContent(char* fileText, const int fileContentSize, FILE* file, int** arrayPtr, const int arrSize) {
    if (GetLineFromFile(fileText, fileContentSize, file)) {
        printf("failed to fetch arrayContent str\n");
        return -1;
    }

    char* arrStr = fileText;
    int scanVal = 0;
    int arrIdx = 0;
    int value = 0;

    while (sscanf(arrStr, "%d%n", &value, &scanVal) == 1) {
        (*arrayPtr)[arrIdx] = value;
        arrIdx++;
        arrStr += scanVal;
    }

    return 0;
}

int parse(char* inputFile, int* sizePtr, int** arrayPtr, int* arrayK) {
    if (inputFile == NULL || sizePtr == NULL || arrayPtr == NULL || arrayK == NULL) {
        return -1;
    }

    //TODO remove FILE*, use stdin instead
    FILE* file = fopen(inputFile, "r");
    if (file == NULL) {
        printf("failed to open file '%s'\n", inputFile);
        return -1;
    }

    const int fileContentSize = 1000000; // 1 mil
    char fileText[fileContentSize];

    // setting array size
    int size = 0;
    if (ParseSingleNr(fileText, fileContentSize, file, &size)) {
        printf("failed to parse arraySize\n");
        // return -1;
    }
    *sizePtr = size;

    (*arrayPtr) = (int*)calloc(sizeof(int), size);

    if ((*arrayPtr) == NULL) {
        printf("failed to create array\n");
        return -1;
    }

    // filling array
    if (ParseArrayContent(fileText, fileContentSize * 6, file, arrayPtr, *sizePtr)) {
        printf("failed to parse arrayContent\n");
    }

    //
    if (ParseSingleNr(fileText, fileContentSize, file, arrayK)) {
        printf("failed to parse arrayK");
    }

    fclose(file);
    file = NULL;

    return 0;
}