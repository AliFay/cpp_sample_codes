/*
 * stateMachine.cpp
 *
 */
#include "stateMachine.h"
#include <iostream>
#include <map>
/*-- State Machine Implementation --*/
//constructor of class EquationList
StateMachine::StateMachine() {
	state_0= ST_A;
	c_state = state_0;
	n_state = c_state;
	std::pair<int,int> p;//make the pair so we put it in the transition map
	p = {ST_A, IN_0};
	transitionMap.insert(std::pair<std::pair<int, int>, funcPtr> (p, &StateMachine::Go_ST_B));
	p = {ST_B, IN_1};
	transitionMap.insert(std::pair<std::pair<int, int>, funcPtr> (p, &StateMachine::Go_ST_C));
	p = {ST_C, IN_2};
	transitionMap.insert(std::pair<std::pair<int, int>, funcPtr> (p, &StateMachine::Go_ST_B));
	p = {ST_C, IN_0};
	transitionMap.insert(std::pair<std::pair<int, int>, funcPtr> (p, &StateMachine::Go_ST_A));
}
/*--copy constructor of class EquationList--*/
StateMachine::StateMachine(const StateMachine& sm) {
	//to do
}
/*-- deconstructor of class LinkedList --*/
StateMachine::~StateMachine() {
	//to do
}
/*-- Run State Machine --*/
void StateMachine::RunStateMachine(int event){
	std::pair<int,int> stateEventPair= {c_state,event}; //make the pair so we use it to look-up the std::map
	if (transitionMap.find(stateEventPair)!= transitionMap.end()) { //if it is in the map
		funcPtr funcTran = transitionMap[stateEventPair]; //grabbing the transition function from map
		n_state = (this->*funcTran)(); //calling the function
		std::cout << "state changed from: " << c_state << " to " << n_state  << std::endl;
		c_state = n_state;
	}
	else
		std::cout << "The status of the system is not changed." << std::endl;
}
/*------------------functions on events --------------*/
int StateMachine::Go_ST_A() {
	return ST_A;
}
int StateMachine::Go_ST_B() {
	return ST_B;
}
int StateMachine::Go_ST_C() {
	return ST_C;
}





