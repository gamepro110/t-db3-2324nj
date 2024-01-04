#include "my_memory.h"
#include "terminal_io.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Please provide argument to select assignment.\n");
        return -1;
    }

    char selectedAssignment = atoi(argv[1]);

    int t = 0; // amount of cases
    int n = 0; // max value(?)
    int m = 0; // lines of x,y points
    

    //TODO make tree node struct
    //TODO parse input

    if (selectedAssignment == 3)
    {
        int shortestPath = 0;
        // FindSmallestNumberThatIsRepeatedKTimes(arr, arrSize, k, &smallestNumber);
        FindShortestPathInGraphTree(&tree, &shortestPath);

        printf("%d\n", shortestPath);
    }
    else if (selectedAssignment == 4)
    {
        int difference = 0;
        // ComputeDifferenceBetweenMaxAndMinSumOfKElements_0(arr, arrSize, k, &difference);
        

        printf("%d\n", difference);
    }
    //----------------------------------------------------------------------------
    const int MemorySize = 100;

    MenuOptions choice = MO_ALLOCATE_MEMORY;
    
    PrintProgramHeader();

    if (argc != 1) {
        fprintf(stderr, "%s: argc=%d\n", argv[0], argc);
    }

    /* initialisate van lijsten dus freeList bevat alle geheugen en allocList is
     * leeg */
    ConstructMemory(MemorySize);

    while (choice != MO_QUIT) {
        choice = GetMenuChoice();

        switch (choice) {
            case MO_ALLOCATE_MEMORY: {
                int nrofBytes = GetInt("Give nr of bytes: ");
                int addr = ClaimMemory(nrofBytes);
                if (addr == -1)
                {
                    printf("[ALLOC] not enough memory for %d byte\n", nrofBytes);
                }
                else
                {
                    printf("[ALLOC] address: %4d (%d byte)\n", addr, nrofBytes);
                }
                break;
            }
            case MO_FREE_MEMORY: {
                int addr = GetInt("Give address to be freed: ");
                int nrofBytes = FreeMemory(addr);
                if (nrofBytes == -1)
                {
                    printf("[FREE]  address: %4d was not allocated\n", addr);
                }
                else
                {
                    printf("[FREE]  address: %4d (%d byte)\n", addr, nrofBytes);
                }
                break;
            }
            case MO_SHOW_LISTS: {
                PrintList(stdout);
                break;
            }
            case MO_SHOW_HIDE_MENU: {
                ToggleMenuPrinting();
                break;
            }
            case MO_QUIT: {
                // nothing to do here
                break;
            }
            default: {
                printf("invalid choice: %d\n", choice);
                break;
            }
        }
    }

    /* opruimen van de lijsten */
    DestructMemory();

    return 0;
}

//! ref <1 intro/main.c>
/*
#include "parser.h"

#include "challenge.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Please provide argument to select assignment.\n");
        return -1;
    }

    char selectedAssignment = atoi(argv[1]);

    int arrSize = 1000000;
    int* arr = NULL; // array, created in parse()
    int k = -1;

    if (parse(&arrSize, &arr, &k) == -1) {
        return -1;
    }

    if (selectedAssignment == 1)
    {
        int smallestNumber = 0;
        FindSmallestNumberThatIsRepeatedKTimes(arr, arrSize, k, &smallestNumber);

        printf("%d\n", smallestNumber);
    }
    else if (selectedAssignment == 2)
    {
        int difference = 0;
        ComputeDifferenceBetweenMaxAndMinSumOfKElements_0(arr, arrSize, k, &difference);

        printf("%d\n", difference);
    }
    else if (selectedAssignment == 31)
    {
        int difference = 0;
        ComputeDifferenceBetweenMaxAndMinSumOfKElements_1(arr, arrSize, k, &difference);
        printf("%d\n", difference);
    }
    else if (selectedAssignment == 32)
    {
        int difference = 0;
        ComputeDifferenceBetweenMaxAndMinSumOfKElements_2(arr, arrSize, k, &difference);
        printf("%d\n", difference);
    }
    else if (selectedAssignment == 33)
    {
        int difference = 0;
        ComputeDifferenceBetweenMaxAndMinSumOfKElements_3(arr, arrSize, k, &difference);
        printf("%d\n", difference);
    }
    else
    {
        printf("Error: Unknown assignment: %d\n", selectedAssignment);
    }

    free(arr);

    return 0;
}
*/