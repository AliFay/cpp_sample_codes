/*
* main.c
*
*  		Created on: Feb 13, 2017
*      	Author: S. Ali Reza Fayazi
*
*
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <inttypes.h>

/* define the inputs (events) */
typedef enum {
  IN_0,
  IN_1,
  IN_2,
} Input;

typedef struct StateMachine StateMachineDeclaration;
typedef void (*state_func)(StateMachineDeclaration *sm, Input in);  //state_func is the pointer to a function for each state
struct StateMachine {  //StateMachine only holds the pointer to the current state
  state_func c_state;
};

/* declare the states (state functions) */
void ST_A(StateMachineDeclaration *sm, Input in);
void ST_B(StateMachineDeclaration *sm, Input in);
void ST_C(StateMachineDeclaration *sm, Input in);

int main()
{
    StateMachineDeclaration sm;
    sm.c_state = ST_A;   // initialize the state machine to state A //or StateMachineDeclaration sm = {ST_A};
    /*example transitions*/
    (sm.c_state)(&sm,IN_2); //forcing an example transition by input 2
    (sm.c_state)(&sm,IN_0); //forcing an example transition by input 0
    (sm.c_state)(&sm,IN_2); //forcing an example transition by input 2
    (sm.c_state)(&sm,IN_1); //forcing an example transition by input 1
    (sm.c_state)(&sm,IN_0); //forcing an example transition by input 0
    return 0;
}

/* define the states (state functions) */
//state A:
void ST_A(StateMachineDeclaration *sm, Input in) {
  if (in==IN_0) {
    sm->c_state = ST_B;
    printf ("state changed from A to B by Event %d\n",in);
  }
  else
    printf ("Staying at state A  by Event %d\n",in);

};
//state B:
void ST_B(StateMachineDeclaration *sm, Input in){
    if (in==IN_1) {
    sm->c_state = ST_C;
    printf ("state changed from B to C  by Event %d\n",in);
  }
  else
    printf ("Staying at state B  by Event %d\n",in);
};
//state C:
void ST_C(StateMachineDeclaration *sm, Input in){
  if (in==IN_2) {
    sm->c_state = ST_B;
    printf ("state changed from C to B  by Event %d\n",in);
  }
  else if (in==IN_0) {
    sm->c_state = ST_A;
    printf ("state changed from C to A  by Event %d\n",in);
  }
  else
    printf ("Staying at state C  by Event %d\n",in);
};

