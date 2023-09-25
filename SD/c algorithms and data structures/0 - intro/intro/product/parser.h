#ifndef PARSER_H_
#define PARSER_H_

/// @brief parses stdin and return an array of numbers
/// @param outputSize size of the output array
/// @param outputArr 
/// @return -1 on fail, 0 on succes
int ParseStdin(int argc_in, char** argv_in, int outputSize, int* outputArr);

int ParseInput(const char* filename, int* arraySize, int* array, int* timesFound);

#endif
