/*
 * main.cpp
 * This is the main file to be compiled
 *
 *  Created on: Jan 25, 2017
 *      Author: S. Ali Reza Fayazi
 */

#include <iostream>
#include "equList.h"

int main() {

	EquationList equList;  //make the equations list

	std::cin >> equList; 	//get the equations from the file (file name entered by the user)

	equList.solveSum(equList); 	//solving the equations (summations, sum of values)

	std::cout << equList;  //print out the equations' solutions (also recorded in output.txt)

	return 0;
}


