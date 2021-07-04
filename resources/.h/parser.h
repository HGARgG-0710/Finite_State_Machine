#include <stdio.h>
#include "./fsm.h"

#ifndef PARSER
#define PARSER

typedef struct
{
    char **keys;
    int **values;
} KeyValue;

typedef struct
{
    char **keys;
    char **values;
} CharKeyValue;

FiniteStateMachine *parseFile(FILE *);
char *parseArray(const char *, int *);
int indexOf(const int[2], const char (*)[], const char *);
void initCharKeyValue(KeyValue *);
int longestValue(const char *, const int, const int);
char *readWhile(const char *, const int *, int (*)(const char));
int isWhitespace(const int);
int isInArray(const int *, const char *, const char **);
int isUnique(const char);
char *deleteSpaces(FILE *);

#endif