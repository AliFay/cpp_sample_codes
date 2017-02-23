/*
 * equList.cpp
 * This is the implementation of the file equList.h
 * This is the implementation of the equaltion list class
 *
 *  Created on: Jan 25, 2017
 *      Author: S. Ali Reza Fayazi
 *
 */

#include "equList.h"
#include <iostream>
#include <map>
#include <utility> //to use Pair
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>


int solveSumRecursiveFun (std::string var, std::map<std::string, std::string>& equ_map,  std::map<std::string, int>& equ_map_solved);
void open_files(std::ifstream& in_stream, const char*);

//constructor of class EquationList
EquationList::EquationList() {
	//to do
}

//copy constructor of class EquationList
EquationList::EquationList(const EquationList& a_list) {
	//to do
}

//deconstructor of class LinkedList
EquationList::~EquationList() {
	//to do
}

//function to sort the equations in ascending order by variable name
void EquationList::sortAscending(EquationList& equ_l) {
	// no need for this function as the elements in std::map are ordered by default
}

//function to solve the equations (summation: sum of values)
void EquationList::solveSum(EquationList& equ_l) {
	int sum; //the summation result
	for (const auto &equ : equ_l.equationsMap)  { //for each item (unsolved equation)
		sum  = solveSumRecursiveFun (equ.second,equ_l.equationsMap,equ_l.equationsMapSolved);
		if (equ_l.equationsMapSolved.find(equ.first)==equ_l.equationsMapSolved.end()) { //if not already solved
			equ_l.equationsMapSolved.insert(std::pair<std::string, int>(equ.first,sum)); //insert the solution in output
		}
	}
}

int solveSumRecursiveFun (std::string rhs,  std::map<std::string, std::string>& equ_map,  std::map<std::string, int>& equ_map_solved) {
	int sum=0; //the summation result
	std::string numbers("0123456789");
	std::string operators("+-*/=");
	std::string item_of_rhs;  		//the item detected in RHS (can be a variable or constant)
	int varValue;
	/**/
	std::istringstream equ_ss(rhs); //read the <RHS> or the right hand side of the equation
	while(equ_ss >> item_of_rhs) {
		/*look if the detected item in RHS is a number*/
		auto posNo = item_of_rhs.find_first_of(numbers); //find the first occurrence of numbers in the identified item
		if (posNo != std::string::npos) {  	//check if a constant number is detected
			sum += stoi(item_of_rhs);  		//convert string number to integer
		}
		/*look if the detected item in RHS is a variable*/
		else {  //if a variable is detected
			auto posOperator= item_of_rhs.find_first_of(operators); //find the first occurrence of operators in the identified item
			if (posOperator==std::string::npos) { 					//skipping any operator detected in RHS
				if (equ_map_solved.find(item_of_rhs)!=equ_map_solved.end()) { //if var is  already solved (improves performance)
					varValue = equ_map_solved[item_of_rhs];
				}
				else {
					varValue  = solveSumRecursiveFun (equ_map[item_of_rhs],equ_map,equ_map_solved); //recursive function
				}
				sum += varValue; //read the variable value from original equation map and convert it to integer
			}
		}
	}
	return sum;
}


//overloaded function to print out the results
std::ostream& operator << (std::ostream& out, EquationList& equ_l) {
	std::ofstream out_stream;
	out_stream.open("output.txt");  //"output_edited_text.dat"
	if (out_stream.fail()) {
		std::cout << "err in output file. \n" << std::endl;
		out_stream.close();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "The following results are recorded in output.txt file:" << std::endl << std::endl;
	for (const auto &equ : equ_l.equationsMapSolved)  { //for each item in the map
		std::cout << equ.first << " = " << equ.second << std::endl; //the 2nd item is the solution in integer
		out_stream << equ.first << " = " << equ.second << std::endl;
	}
}

//overloaded function to get the equations
std::istream& operator >>(std::istream& in, EquationList& equ_l) {  //overloading function for << operator
	std::string equationStr;
	std::string line;
	std::string rhs;
	std::string lhs;
	std::string separators(" ="); //space and "="
	int cnt=1;

	/*define the streams */
	std::ifstream in_stream;
	/*open the file*/
	in_stream.open("input.txt");
	if (in_stream.fail()) {
		std::cout << "error in input file. File not found! \n";
		in_stream.close();
	}
	std::cout <<  "The specification of equations are received from file input.txt " << std::endl;

	while (std::getline(in_stream,line)) { //read file line by line
		auto equLoc=line.find_first_of(separators); //find the location of the '=' operator or any "space"
		lhs= line.substr(0,equLoc); //get LHS
		line.erase(0,equLoc);		//erase LHS
		rhs = line;  //get RHS
		equ_l.equationsMap.insert(std::pair<std::string, std::string>(lhs,rhs));
	}
	for (auto &equ: equ_l.equationsMap) {
		std::cout << "Input Equation (" << cnt++ << "): " << equ.first << equ.second << std::endl;
	}
	/*
		equ_l.equationsMap = {{"location","= 1 + origin + offset"},
				{"offset","= 4 +  random + 1"},
				{"origin"," = 3 +     5"},
				{"random","= 2 "}};
	*/
}

