#include <stdio.h>
#include "./fsm.h"
#include "./pairs.h"

#ifndef PARSER
#define PARSER
 
FiniteStateMachine *parseFile(FILE *);
char *parseArray(const char *, int *);
int indexOf(const int[2], const char (*)[], const char *);
void initCharKeyValue(KeyValue *);
int longestValue(const char *, const int, const int);
char *readWhile(const char *, const int *, int (*)(const char));
int isWhitespace(const int);
int isInArray(const int *, const char *, const char **);
int isUnique(const char);
int isKeyword(const char *string);
char *deleteSpaces(FILE *);

#endif