#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#include "mystack.h"

const uint8_t bufferSize = 50;
const uint8_t numElements = 10;

typedef struct data Data;
struct data{
    int num;
    double info;
    // char buffer[bufferSize];
};

// int argc, char * argv[]
int main (void) {
    printf("Hello world!\n");
    int handle = 0;
    int count = 1;

    while (count > 0) {
        printf("create\n");
        handle = MystackCreate(sizeof(Data));

        if (handle == -1) {
            return -1;
        }

        printf("pre push\n");
        for (int i = 0; i < numElements; i++) {
            Data* data = calloc(1, sizeof(Data));
            data->num = i;
            data->info = 3.14159 * i;
            if (MystackPush(handle, data)) {
                printf("failed to make data %-3d\n", i);
            }
        }

        printf("post push\n");
        printf("num elements: %-5d\n", MystackNofElem(handle));
        printf("pre pop\n");

        for (int i = 0; i < numElements; i++) {
            Data data;
            if (MystackPop(handle, &data)) {
                printf("%*d", 3, data.num);
            }
        }
        printf("\n");
        printf("post pop\n");

        if (MystackDestroy(handle)) {
            printf("failed to destroy stack");
        }
    }

    return 0;
}
