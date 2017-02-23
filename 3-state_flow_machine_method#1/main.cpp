/*
 * main.cpp
 *
 *  Created on: Jan 27, 2017
 *  Author: S. A. Fayazi
*
*  The code implements the state machine shown below in C++ using std::map:
*
*         ------------                 	  	  -------------
*         |  State   |						 |	  State   |
*         |     A    |--------Event 0------->|	    B	  |
*		  |          |						 |			  |
*         ------------						  -------------
*				^		    					|		^
*				|								|    	|
*				|							Event 1   	|
*				|								|    Event 2
*			Event 0								|  	 	|
*				|								V   	|
*				|               			----------------
*				|							|	  State     |
*				----------------------------|	    C	    |
*											|			    |
*											-----------------
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

