#include "challenge.h"

#include <stddef.h>
#include <stdio.h>

/// @brief checks if given array contains given number and returns the index if found
/// @param number element to be found
/// @param index first index of the requested number
/// @return -1 on error, 0 on found, 1 on NOT found
int contains(int arraySize, int array[arraySize], int number, int* index)
{
    if (array == NULL || index == NULL)
    {
        return -1;
    }

    int idx = 0;
    int done = 0;
    while (idx <= arraySize && done == 0)
    {
        if (array[idx] == number)
        {
            done = 1;
            *index = idx;
        }

        idx++;
    }

    return !done;
}

/// @brief return which numbers have been found and how many in the input array
/// @return -1 on fail, 0 on succes
int parseArray(int inputSize, int inputArray[inputSize], int outputArray[inputSize], int outputCount[inputSize])
{
    if (inputArray == NULL || outputArray == NULL || outputCount == NULL)
    {
        return -1;
    }

    int idx = 0;
    int whileCount = 1000;

    for (int i = 0; i < inputSize; i++)
    {
        outputArray[i] = 0;
        outputCount[i] = 0;
    }

    int writeIdx = 0;

    while (idx < inputSize && whileCount > 0)
    {
        int num = inputArray[idx];
        int countIdx = 0;
        if (0 == contains(inputSize, outputArray, num, &countIdx))
        {
            outputCount[countIdx]++;
        }
        else
        {
            outputArray[writeIdx] = num;
            outputCount[writeIdx]++;
            writeIdx++;
        }

        idx++;
        whileCount--;
    }

    return 0;
}

int FindSmallestNumberThatIsRepeatedKTimes(
            int* array, int size, int k, int* smallestNumber)
{
    if (array == NULL || smallestNumber == NULL)
    {
        return -1;
    }

    int returnVal = 0;
    int smallest = 10000;

    int numArray[size];
    int numCount[size];

    if (-1 == parseArray(size, array, numArray, numCount))
    {
        returnVal = -1;
    }
    else
    {
        int foundIdx = 0;
        while (foundIdx < size)
        {
            int amountFound = numCount[foundIdx];
            if (amountFound == k)
            {
                int foundNum = numArray[foundIdx];
                if (foundNum < smallest)
                {
                    smallest = foundNum;
                }
            }

            foundIdx++;
        }
    }

    *smallestNumber = smallest;

    return returnVal;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_0(
            int* array, int size, int k, int* difference)
{
    if (array == NULL || difference == NULL)
    {
        return -1;
    }

    int numArray[size];
    int numCount[size];
    int largest = 0;
    int smallest = 1000000;

    parseArray(size, array, numArray, numCount);

    //TODO find smallest
    //|--- use `FindSmallestNumberThatIsRepeatedKTimes` as template for function finding smallest
    //TODO find largest
    
    // multiply by -1 to invert negative
    *difference = (largest - smallest) * -1;

    return 0;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_1(
            int* array, int size, int k, int* difference)
{
    return -1;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_2(
            int* array, int size, int k, int* difference)
{
    return -1;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_3(
            int* array, int size, int k, int* difference)
{
    return -1;
}
