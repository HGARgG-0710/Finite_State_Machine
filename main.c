#include <stdio.h>

#include "./resources/.h/parser.h"
#include "./resources/.h/fsm.h"
#include "./resources/.h/process.h"

int main()
{
    const char *filename;

    printf("This is the program for simulating the behavior of the specially pre-configured FSM.\nPlease input the name of the text file, which contains the configuration: ");
    scanf("%s", &filename);

    FILE *inputFile = fopen(*filename, "r");
    FiniteStateMachine* fsm = parseFile(inputFile);
    
    close(inputFile);
}