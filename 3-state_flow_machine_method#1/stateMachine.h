/*
 * stateMachine.h
 *
 */
#include <map>

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

//define possible states:
#define ST_A             0
#define ST_B             1
#define ST_C             2

//define possible events:
#define IN_0      5000
#define IN_1      5001
#define IN_2      5002

class StateMachine;

typedef int (StateMachine::*funcPtr)(void);  //pointer to a function

class StateMachine
{
public:
	StateMachine(); //default constructor
	StateMachine(const StateMachine& sm); //copy constructor
	~StateMachine();
	void RunStateMachine(int event);
private:
	int Go_ST_A (void);  	//static
	int Go_ST_B (void);  	//static
	int Go_ST_C (void);  	//static
	int state_0;
	int c_state;
	int n_state;
	std::map<std::pair<int, int>, funcPtr> transitionMap;  //The state machine map (includes the function pointers)
};
#endif /* STATEMACHINE_H_ */
