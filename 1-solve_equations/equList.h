/*
 * equList.h
 *
 *  Created on: Jan 25, 2017
 *      Author: S. Ali Reza Fayazi
 *
 */
#include <iostream> //to use cout cin
#include <map>
#include <string>

#ifndef EQULIST_H_
#define EQULIST_H_

/*
 * Class definition for the list of equations
 */

class EquationList {
	friend std::ostream& operator <<(std::ostream& out, EquationList& equ_l);  //overloading function for >> operator
	friend std::istream& operator >>(std::istream& in, EquationList& equ_l);  //overloading function for << operator
public:
	EquationList(); //default constructor
	EquationList(const EquationList& a_list); //copy constructor
	~EquationList();
	void sortAscending(EquationList& equ_l); //sorting the equation list based on the variables (ascending)
	void solveSum(EquationList& equ_l); //solving the equations (summations, sum of values)
private:
	std::map<std::string, std::string> equationsMap; //includes the original equation definition (1st item of the map =variable, 2nd item of the map= definition)
	std::map<std::string, int> equationsMapSolved;   //includes the equation solutions (1st item of the map =variable, 2nd item of the map= solution)
};

#endif /* EQULIST_H_ */
