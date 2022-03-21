#include <stdio.h>
#include <string.h>

#include "./.h/process.h"
#include "./.h/fsm.h"

void processStateChange(FiniteStateMachine *fsm)
{
    char *currTransition;

    do
    {
        printf("Please, input the next transition, that should happen to the %s FSM:", *fsm->fsm_name);
        scanf("%s", &currTransition);

        // Check if the inputted transition is in the fms->transitions or not.
        // If so, then change the fsm->currState field using the fsm pointer.
        // else, printf("Sorry, the inputted transition is not specified in the FSM configuration.")
        // ! For this, use the isInArray() function, you have written earlier.

    } while (strcmp(currTransition, *fsm->exitWord));

    printf("Thank you for using the app! :)");
    free(fsm);
}