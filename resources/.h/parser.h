#include <stdio.h>
#include "./fsm.h"

#ifndef PARSER
#define PARSER

struct KeyValue
{
    char **keys;
    int **values;
};

FiniteStateMachine *parseFile(FILE *);
char *parseArray(char *, int);
int indexOf(const int[2], const char (*)[], const char *);
void initCharKeyValue(struct KeyValue *keyValue);
struct KeyValue *countStuff();

#endif