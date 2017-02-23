/*
 * main.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: S. Ali Reza Fayazi
 *
 *
 *      This program prints all permutations of a string that can be found in another string.
 *      For example, looking for the permutations of "eggs" in the "hsgegsdsgbaggsgeheagssgegs",
 *      the program prints as follows:
 *      found: sgeg
 *      found: gegs
 *      found: gsge
 *      found: sgeg
 *      found: gegs
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>

void get_input(std::string& input_string, std::string& permutations_string);
void print_premutation(std::string found);
/*-----------------------------------------------------------------------------*/
int main () {
	int index_on_list;
	int location;
	char tmp;
	std::string list_org;  		//the string that your are looking for its permutations
	std::string input_string; 	//the input string

	get_input(input_string,list_org);  	//get inputs from the user
	std::string list_cpy(list_org); 	//make a copy of the string

	for (int index=0; index < (input_string.length()-list_org.length()+1); index++) {
		list_cpy=list_org; 		//reset the copy list
		tmp = input_string[index]; //grab one char
		index_on_list=index;
		while(1){
			location = list_cpy.find(tmp);  	//find the location of the char
			if (location>=0 && location<=list_cpy.length()) { //if the char exists in the list_cpy (copy of the main string)
				list_cpy.erase(location,1); 	//erasing the item from the string
			}
			else {
				location = list_org.find(tmp); 	//if not in the copy list then search in the original list
				if (location>=0 && location<=list_org.length()) //if it is in the original list then break the loop and start over
					break;
				else {
					index=index_on_list; //if not in the original list then save on performance by jumping forward on the string list
					break;
				}
			}
			if (list_cpy.empty()) {
				print_premutation(input_string.substr(index,list_org.length()));
				break;
			}
			tmp = input_string[++index_on_list]; //grab the next char
		}
	}
	return 0;
}
/*-----------------------------------------------------------------------------*/
void get_input(std::string& input_string, std::string& permutations_string) {
	std::cout << "please type the main string (e.g. hsgegsdsgbaggsgeheagssgegs)" << std::endl;
	getline(std::cin,input_string);
	std::cout << "please type the string that your are looking for its permutations (e.g. eggs)" << std::endl;
	getline(std::cin,permutations_string);
    if (*permutations_string.rbegin() == '\r') //remove the carriage return
    	permutations_string.erase(permutations_string.length() - 1);
}
/*-----------------------------------------------------------------------------*/
void print_premutation(std::string found) {
	std::cout << "found: " << found << std::endl;
}

