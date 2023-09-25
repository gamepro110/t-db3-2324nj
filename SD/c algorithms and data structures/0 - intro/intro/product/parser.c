#include "parser.h"

#include <stdlib.h>
#include <stddef.h>

#include <stdio.h>
#include <string.h>

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

int ParseInput(const char *filename, int *arraySize, int *array, int *timesFound)
{
    if (filename == NULL || arraySize == NULL || array == NULL || timesFound == NULL)
    {
        return -1;
    }
    
    const int strSize = 20;
    char sizeStr[strSize];
    char arrayStr[strSize];
    char timesStr[strSize];
    
    FILE* fp = fopen(filename, "r");

    if (fp == -1)
    {
        printf("failed to open file");
        return -1;
    }

    //FIXME invalid in/out put for fscanf
    if (fscanf(fp, "%[^\n]", sizeStr) == EOF)
    {
        printf("failed to read first line");
        return -1;
    }
    if (fscanf(fp, "%[^\n]", arrayStr) == EOF)
    {
        printf("failed to read second line");
        return -1;
    }
    if (fscanf(fp, "%[^\n]", timesStr) != EOF)
    {
        printf("failed to read third line");
        return -1;
    }
    fclose(fp);
    fp = NULL;

    // parsing first line
    *arraySize = 4;//FIXME temp
    
    sscanf(sizeStr, "%d", arraySize);
    
    // parsing second line
    char* begin = arrayStr;
    char* end = NULL;
    int arrIdx = 0;
    int subStrSize = 0;
    while (begin != NULL)
    {
        end = strchr(begin, ' ');
        
        if (end != NULL) {
            subStrSize = end - begin;
        }
        else
        {
            subStrSize = strlen(begin);
        }

        int num = 0;
        for (int i = 0; i < subStrSize; i++)
        {
            int subNum = begin[i] - '0';
            if (subNum < -1 && subNum > 9)
            {
                if (i < 0)
                {
                    num *= 10;
                }

                num += subNum;
            }
        }

        array[arrIdx] = num;
        arrIdx++;

        begin = end;
    }

    // parsing third line
    sscanf(timesStr, "%d", timesFound);

    return 0;
}
