#include "parser.h"

#include "challenge.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 3) // 2 originally
    {
        printf("Please provide argument to select assignment.\n");
        return -1;
    }

    char selectedAssignment = atoi(argv[1]);

    printf("assignment: %d f: '%s'\t", selectedAssignment, argv[argc -1]);

    int arrSize = 1000000;
    int* arr = NULL; // array, created in parse()
    int k = -1;

    if (parse(argv[2], &arrSize, &arr, &k) == -1) {
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