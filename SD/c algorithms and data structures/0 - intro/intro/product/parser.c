#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool CheckSubStrNull(const char* sub) {
    return sub == NULL;
}

int parse(char* inputFile, int* sizePtr, int* arrayPtr) {
    if (inputFile == NULL || sizePtr == NULL || arrayPtr == NULL) {
        return -1;
    }

    FILE* file = fopen(inputFile, "r");
    if (file == NULL) {
        printf("failed to open file '%s'\n", inputFile);
        return -1;
    }
    
    const size_t fileContentSize = 100;
    char fileText[fileContentSize];
    char* retVal = fgets(fileText, fileContentSize, file);
    fclose(file);
    file = NULL;

    if (retVal != fileText) {
        return -1;
    }

    printf("fileText: '%s'", fileText);

    char* substr = NULL;
    const char delim[] = "\n";
    substr = strtok(fileText, delim);

    char* sizeStr = substr;
    substr = strtok(NULL, delim);

    char* arrStr = substr;
    substr = strtok(NULL, delim);

    char* answerStr = substr;
    substr = strtok(NULL, delim);

    if (CheckSubStrNull(substr) && (!CheckSubStrNull(sizeStr) || !CheckSubStrNull(arrStr) || !CheckSubStrNull(answerStr))) {
        printf("substr in unexpectedState\n");
        return -1;
    }

    // setting array size
    (*sizePtr) = atoi(sizeStr);
    printf("arraySize: '%s'\n", substr);

    //temp
    printf("arrStr: '%s'\n", arrStr);
    printf("answerStr: '%s'\n", answerStr);
    //temp

    // filling array
    // substr = strtok(fileText, "\n");
    substr = strtok(NULL, "\n");
    char* value = NULL;
    int size = (*sizePtr);

    for (size_t i = 0; i < size; i++) {
        value = strtok(NULL, " ");

        if (value == NULL) {
            printf("failed to parse array format\n");
            return -1;
        }

        arrayPtr[i] = atoi(value);
    }

    return 0;
}