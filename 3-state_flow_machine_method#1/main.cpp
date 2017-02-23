/*
 * main.cpp
 *
 *  Created on: Jan 27, 2017
 *  Author: S. A. Fayazi
*
*/

#include "stateMachine.h"

/*--------------------------------------------------------------*/
int main () {
	StateMachine sm;

    /*example transitions*/
	sm.RunStateMachine(IN_2); //forcing an example transition by input 2
	sm.RunStateMachine(IN_0); //forcing an example transition by input 0
	sm.RunStateMachine(IN_2); //forcing an example transition by input 2
	sm.RunStateMachine(IN_1); //forcing an example transition by input 1
	sm.RunStateMachine(IN_0); //forcing an example transition by input 0

	return 0;
}
/*---------------------------------------------------------------*/

