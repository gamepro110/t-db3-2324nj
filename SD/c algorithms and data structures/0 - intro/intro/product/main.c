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

    for (int i = 0; i < argc; i++) {
        printf("argv %x: %s\n", i, argv[i]);
    }

    char selectedAssignment = atoi(argv[1]);

    int arrSize = 1000000;
    int arr[arrSize];
    int k = -1;

    if (parse(argv[2], &arrSize, arr) == -1) {
        return -1;
    }

    // TODO: parse data from stdin as explained in part 0 in the challenge document
    // (obviously: parsing data is another responsibility than commandline UI stuff,
    //  so parsing data should happen in another file!)

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

    return 0;
}