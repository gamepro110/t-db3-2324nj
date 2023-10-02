#include "parser.h"

#include "challenge.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 3) // changed
    {
        printf("Please provide argument to select assignment.\n");
        printf("argc: %d\n", argc);
        for (int i = 0; i < argc; i++)
        {
            printf("%s\n", argv[i]);
        }
        printf("\n");
        
        return -1;
    }
    char selectedAssignment = atoi(argv[1]);

    // TODO: parse data from stdin as explained in part 0 in the challenge document
    // (obviously: parsing data is another responsibility than commandline UI stuff,
    //  so parsing data should happen in another file!)
    
    
    //TODO change parseStdin to requirements in pdf
    //TODO make function 
    //--------------------
    int arraySize = 100000;
    int array[arraySize];
    int K = -1;
    ParseInput(argv[2], &arraySize, array, &K);
    // if (-1 == ParseStdin(argc, argv, arraySize, array))
    // {
        // printf("failed to parse input.\n");
        // return -1;
    // }
    //--------------------

    if (selectedAssignment == 1)
    {
        int smallestNumber = 0;
        // TODO fix magic num 2
        FindSmallestNumberThatIsRepeatedKTimes(array, arraySize, K, &smallestNumber);

        printf("%d\n", smallestNumber);
    }
    else if (selectedAssignment == 2)
    {
        int difference = 0;
        ComputeDifferenceBetweenMaxAndMinSumOfKElements_0(array, arraySize, K, &difference);

        printf("%d\n", difference);
    }
    else if (selectedAssignment == 31)
    {
        int difference = 0;
        //ComputeDifferenceBetweenMaxAndMinSumOfKElements_1( /* TODO: fill in parameters */ );
        printf("%d\n", difference);
    }
    else if (selectedAssignment == 32)
    {
        int difference = 0;
        //ComputeDifferenceBetweenMaxAndMinSumOfKElements_2( /* TODO: fill in parameters */ );
        printf("%d\n", difference);
    }
    else if (selectedAssignment == 33)
    {
        int difference = 0;
        //ComputeDifferenceBetweenMaxAndMinSumOfKElements_3( /* TODO: fill in parameters */ );
        printf("%d\n", difference);
    }
    else
    {
        printf("Error: Unknown assignment: %d\n", selectedAssignment);
    }

    return 0;
}
