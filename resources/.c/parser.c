#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>

#include "./.h/parser.h"
#include "./.h/fsm.h"

const char unique[][2] = {",", "{", "}", ":"};
const char keywords[][12] = {"name", "end", "states", "transitions", "start_state"};

const int *uniqueSizes = {4, 2};
const int *keywordSizes = {5, 12};

FiniteStateMachine *parseFile(FILE *inputFile)
{
    const char *cleanedFile = deleteSpaces(inputFile);
    const int length = strlen(cleanedFile);

    CharKeyValue pairs = {.keys = keywords, .values = (char *)malloc(5 * sizeof(char *))};
    const int longest = longestValue(cleanedFile, 0, length);

    for (int i = 0; i < 5; i++)
        pairs.values[i] = (char)malloc((longest + 1) * sizeof(char));

    char *currKey;
    char *currValue;

    for (char currChar, i = 0; i < length; i++)
    {
        currKey = readWhile(cleanedFile, i, !isUnique);
        currChar = cleanedFile[++i]; // skiping the ":" unique
        currValue = currChar == "{" ? parseArray(cleanedFile, &i) : readWhile(cleanedFile, i, !isUnique);

        free(currKey);
        free(currValue);
    }

    // TODO: Init finite state machine.
    FiniteStateMachine fsm;

    // TODO: Free memory, allocated for the pairs struct.

    free(longest);
    return &fsm;
}

char *parseArray(const char *inputFile, int *position)
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

int longestValue(const char *inputFile, const int positon, const int length)
{
    int longest = 0;
    int currLength = 0;

    char *currValue;
    int position = 0;

    for (char currChar; position < length; position++)
    {
        currChar = inputFile[position];
        free(readWhile(inputFile, position, !isUnique)); // skipping the keys (we do not care 'bout them)
        currChar = inputFile[++position];                // skipping the ":"

        if (currChar == "{")
        {
            while (currChar != "}")
            {
                currValue = readWhile(inputFile, ++position, !isUnique);
                currLength += strlen(currValue);
                free(currValue);
            }
            position++; // skipping the ","
        }
        else
        {
            currValue = readWhile(inputFile, position, !isUnique);
            currLength = strlen(currValue);
            free(currValue);
        }

        if (currLength > longest)
        {
            longest = currLength;
            currLength = 0;
        }
    }

    return longest;
}

void initCharKeyValue(KeyValue *keyValue)
{
}

char *readWhile(const char *inputFile, const int *start, int (*condition)(const char))
{
    const original = *start;
    int i = start;
    for (int currChar; condition(currChar); i++)
        currChar = inputFile;

    const int length = i - original;
    char *read = (char *)malloc(sizeof(char) * (length + 1));

    for (int j = 0; j < length; j++)
        read[j] = inputFile[original + j];

    return read; // (i - original) is equal to the length of the new string
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

int isKeyword(const char *string)
{
    return isInArray(keywordSizes, string, keywords);
}

char *deleteSpaces(FILE *inputFile)
{
    int length = 0;
    char currChar;

    for (; (currChar = getc(inputFile)) != EOF; length++)
    {
        if (isWhitespace(currChar))
            length--;
    }

    rewind(inputFile);

    char *cleared = (char *)malloc(sizeof(char) * length);
    for (int i = 0; (currChar = getc(inputFile)) != EOF; i++)
    {
        if (isWhitespace(currChar))
        {
            i--;
            break;
        }

        cleared[i] = currChar;
    }

    fclose(inputFile);

    return cleared;
}