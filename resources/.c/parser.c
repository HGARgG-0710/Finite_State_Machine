#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./.h/parser.h"
#include "./.h/fsm.h"

const char unique[][2] = {",", "{", "}", ":"};
const char keywords[][12] = {"name", "end", "states", "transitions", "start_state"};

const int *uniqueSizes = {4, 2};

FiniteStateMachine *parseFile(FILE *inputFile)
{
    CharKeyValue pairs = {.keys = keywords, .values = (char *)malloc(5 * sizeof(char *))};
    const int longest = longestValue(inputFile, 0);

    for (int i = 0; i < longest; i++)
        pairs.values[i] = (char)malloc(5 * sizeof(char));

    char *currKey;
    char *currValue;

    for (int currChar, i = 0; (currChar = getc(inputFile)) != EOF; i++)
    {
        free(readWhile(inputFile, i, isWhitespace));

        if ((currChar = getc(inputFile)) == EOF)
            break;
        else
            i++;

        currKey = readUntilUnique(inputFile, i, !isUnique);
        currValue = readUntilUnique(inputFile, i, !isUnique);

        free(currKey);
        free(currValue);
    }

    fclose(inputFile);

    // TODO: Do the manual dynamic allocation using malloc();
    FiniteStateMachine fsm;

    // TODO: Free memory, allocated for the pairs struct.

    return &fsm;
}

KeyValue *parseArray(char *inputFile, int position)
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

int *longestValue(const FILE *inputFile, const int positon)
{
    // TODO: Add the finding of the longest value for the key-value configuration.
    rewind(inputFile);
}

void initCharKeyValue(KeyValue *keyValue)
{
}

char *readWhile(const FILE *inputFile, const int *start, int (*condition)(const char))
{
    const original = *start;
    int i = start;
    for (int currChar; condition(currChar) && (currChar = getc(inputFile)) != EOF; i++)
        ;

    return (char *)malloc(sizeof(char) * (i - original + 1)); // (i - original) is equal to the length of the new string
}

int isWhitespace(const int character)
{
    return character == ' ' || character == "\n";
}

int isInArray(const int *sizes, const char *string, const char **array)
{
    return indexOf(sizes, array, string) != -1;
}

int isUnique(const char character)
{
    return isInArray(uniqueSizes, strcat(character, '\0'), unique);
}