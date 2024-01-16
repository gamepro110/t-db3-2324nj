#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#include "mystack.h"

#define cleanupBackwards 1

const uint8_t numElements = 100;
const uint8_t numIterations = 10;

const uint8_t bufferSize = 50;
typedef struct data Data;
struct data{
    int num;
    double info;
    // char buffer[bufferSize];
};

void printData(Data* data);
void FillStack(int handle);

// int argc, char * argv[]
int main (void) {
    printf("Hello world!\n");
    int handle = 0;
    int count = 0;

    while (count < numIterations) {
        handle = MystackCreate(sizeof(Data));
        printf("created handle %d\n", handle);

        if (handle == -1) {
            return -1;
        }

        printf("pre push\n");
        FillStack(handle);

        printf("post push\n");
        printf("num elements: %-5d\n", MystackNofElem(handle));
        printf("pre pop\n");

        for (int i = 0; i < numElements; i++) {
            Data data = { 0, 0.0 };
            if (MystackPop(handle, &data) != -1) {
                printData(&data);
            }
        }
        printf("post pop\n");

        printf("\n");
        count++;
    }

#   if cleanupBackwards
    for (int i = numIterations; i > 0; i--) {
        if(MystackDestroy(i) == -1) {
            printf("failed to destroy stack\n");
        }
    }
#   else
    for (int i = 1; i <= numIterations; i++) {
        if (MystackDestroy(i) == -1) {
            printf("failed to destroy stack\n");
        }
    }
#   endif

    return 0;
}

void printData(Data* data) {
    if (data == NULL) {
        return;
    }

    printf(" %3d_%-6.2f\n", data->num, data->info);
}

void FillStack(int handle) {
    for (int i = 0; i < numElements; i++) {
        Data* data = calloc(1, sizeof(Data));
        data->num = i;
        data->info = (i * 10) + 3.14159;
        printData(data);

        if (MystackPush(handle, data)) {
            printf("failed to make data %-3d\n", i);
        }
    }
}
