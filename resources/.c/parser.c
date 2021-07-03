#include <stdio.h>
#include <string.h>

#include "./.h/parser.h"
#include "./.h/fsm.h"

FiniteStateMachine *parseFile(FILE *inputFile)
{
}

char *parseArray(char *inputStr, int arrIndex)
{
}

/**
 * This function returns the index of a string in a string array.
 * @param sizes The pointer integer array, which size is equal to 2. First element represents the first size of the strArr array, seconde one - the second.
 * @param strArr The array of char[] pointers, which is to be searched for the searchWord. 
 * @param searchedStr The string that is to be searched in the strArr array. 
 * @returns A position of the searchedStr in the strArr, if found. Else, -1.
*/
int indexOf(const int sizes[2], const char strArr[sizes[0]][sizes[1]], const char *searchedStr)
{
    for (int i = 0; i < sizes[0]; i++)
        if (!strcmp(strArr[i], searchedStr))
            return i;

    return -1;
}

struct KeyValue *countStuff(char *inputStr)
{
}

void initCharKeyValue(struct KeyValue *keyValue)
{
}