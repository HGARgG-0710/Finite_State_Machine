# Finite State Machine Simulator

## What is it?

I've decided to spend some time on another fun programming task, that I've found on the Net, which is building your own FSM from scratch in C.
Then I thought, "Hang on, what if I try to generalize this task and create something like an FMS simulator?"
And so, I'm doing it.

The FMS is gonna be taking some configuration on the FSM, that you wish to simulate.
Of course, it will have some limitations (like, for example the fact, that you cannot create very complex FMS with it, just a fairly simple one).
Configuration consists of this:

    - name of the FSM,
    - its starting state,
    - the word for ending the fsm,
    - the list of states for it,
    - the list of possible transitions for it.

! Warning !: One transition can be mapped to only one state and to do it, you need to place them at the same spot in different list
(The indexes of theirs in these lists must be equal).

## Development

The project is in development at the current moment, it progresses and I hope, that fairly soon the machine simulator
will work.
