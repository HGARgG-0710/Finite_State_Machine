#ifndef FSM
#define FSM

typedef struct
{
    int sizes[2];
    char *transitions[];
} FSM_Transitions;

typedef struct
{
    int sizes[2];
    char *states[];
} FSM_States;

typedef struct
{
    FSM_Transitions transitions;
    FSM_States states;

    int struct_size;

    char *fsm_name;
    char *currState;
    char *exitWord;
} FiniteStateMachine;

void initFiniteStateMachine(FiniteStateMachine *, char[], char[]);
void makeTransition(FiniteStateMachine *, char[]);

#endif