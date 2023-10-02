#include "parser.h"

#include <string.h>

#include <stdio.h>
#include <stdlib.h>

/*
int ParseStdin(int argc_in, char **argv_in, int outputSize, int *outputArr)
{
    if (argv_in == NULL || outputArr == NULL || outputSize < (argc_in - 2)) {
        return -1;
    }

    char* output = NULL;
    int num = -1;
    int outputIdx = 0;
    for (int i = 0; i < outputSize && outputIdx < outputSize; i++)
    {
        output = argv_in[2 + i];
        num = atoi(output);
        if (num)
        {
            output[outputIdx] = num;
        }
    }
    

    return 0;
}
//*/

int readFileToBuffer(const int bufferSize, char* buffer, FILE* fp)
{
    // src: <https://stackoverflow.com/a/2029227>
    if (buffer == NULL || fp == NULL) {
        printf("buffer or fp was null\n");
        return -1;
    }

    size_t newLen = fread(buffer, sizeof(char), bufferSize, fp);
    if (ferror(fp) != 0)
    {
        printf("failed to read file");
    }
    else {
        buffer[newLen] = '\0';
    }

    //FIXME getline() not found in stdio.h?? while <https://linux.die.net/man/3/getline> says it is
    return 0; //(*read = getline(buffer, len, fp));
}

/// @return -1 on failure, 0 on succes
int getNumberFromStr(const int bufferSize, char* buffer, int* num, char* remainingStr, char seperator)
{
    if (buffer == NULL || num == NULL)
    {
        return -1;
    }

    int bufSize = strlen(buffer);

    char* start = buffer;
    char* end = NULL;
    size_t strLen = 0;
    int total = 0;

    end = strchr(start, seperator);

    if (end)
    {
        strLen = (end - start);
    }
    else
    {
        strLen = strlen(start);
    }

    int tempNum = 0;

    for (size_t i = 0; i < strLen; i++)
    {
        tempNum = start[i] - '0';

        if (tempNum > -1 && tempNum < 10)
        {
            if (i > 0)
            {
                total *= 10;
            }

            total += tempNum;
        }
    }

    *num = total;

    int idx = 0;
    char c = buffer[idx + strLen + 1];
    int newlineOrNullFound = 0;

    while (idx <= bufSize)
    {
        // +1 to skip over the seperator
        c = buffer[idx + strLen + 1];

        if (c == '\n' || c == '\0')
        {
            newlineOrNullFound++;
        }

        
        if (newlineOrNullFound == 0)
        {
            remainingStr[idx] =  c;
        }
        else
        {
            remainingStr[idx] =  '\0';
        }

        idx++;
    }

    return 0;
}

//TODO
int parseLastNum()
{
    // <https://chat.openai.com/share/5f2a1deb-4301-469c-8224-7551341dce71>
    return -1;
}

int ParseInput(const char* filename, int* arraySize, int* array, int* timesFound)
{
    if (filename == NULL || arraySize == NULL || array == NULL || timesFound == NULL)
    {
        return -1;
    }

    //const int strSize = 20;

    FILE* fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("failed to open file");
        return -1;
    }

    const int maxBufferSize = 100;
    char buffer[maxBufferSize];

    if (readFileToBuffer(maxBufferSize, buffer, fp) == -1)
    {
        printf("failed to read buffer\n");
    }


    fclose(fp);
    fp = NULL;

    char remainingStr[maxBufferSize];
    memset(remainingStr, '\0', maxBufferSize);

    if (getNumberFromStr(maxBufferSize, buffer, arraySize, remainingStr, '\n') == -1) {
        printf("failed to parse first num\n");
    }

    char sep = ' ';
    for (int i = 0; i < *arraySize; i++)
    {
        int loopNum = 0;

        if (getNumberFromStr(maxBufferSize, remainingStr, &loopNum, remainingStr, sep) == -1)
        {
            printf("failed to parse array content\n");
            break;
        }
        //printf("i->%d: %d, remain: %s \n", i, loopNum, remainingStr);

        array[i] = loopNum;
    }

    //TODO move parsing lines to seperate functions
    // getting the numbers from the second line to fill the array

    // getting the values
    ///*
    printf("read size: %d\n", *arraySize);
    printf("read arr: `");
    for (int i = 0; i < *arraySize; i++)
    {
        printf("%d", array[i]);

        if (i < (*arraySize) -1)
        {
            printf(", ");
        }
    }
    printf("`\n");

    if (parseLastNum() == -1)
    {
        printf("failed to parse last num\n");
        return -1;
    }

    //sscanf(buffer, "%s\n%s\n%d", timesFound);
    //TODO fix below
    printf("expected times read: %d\n", *timesFound);
    //*/

    return 0;
}
