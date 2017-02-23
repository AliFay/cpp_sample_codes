/*
 *  Determining if a string has all unique characters
 *
 *  Created on: Jan, 2017
 *  Author: S. Ali Reza Fayazi
 *
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

bool is_unique(std::string& str);
/*------------------------------------------------------*/
int main () {
	std::string str;
	std::cout << " Enter the input string to determine if it has all unique characters: "  << std::endl;
	getline(std::cin,str); //get input string
	std::cout << "The input string " <<
			((is_unique(str))  // conditional print
		    ? "is "
		    : "is not "
		    ) << "unique!" << std::endl;
	return 0;
}
/*------------------------------------------------------*/
bool is_unique(std::string& str){
	std::vector<bool> char_flag(128);  //use a vector to flag the characters; assuming 128 chars totally.
	unsigned int char_index;
	for (unsigned int i=0; i<str.length(); i++) {
		if (!isspace(str[i])) {
			char_index= (int) str[i];
			if (char_flag[char_index])  //if already flagged then the string is not unique
				return false;
			char_flag[char_index] =1;  //flag the char
		}
	}
	return true;
}
