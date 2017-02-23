/*
 * main.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: S. Ali Reza Fayazi
 *      Based on C++ Primer (5th Edition)
 */

#include <vector>
#include <iostream>

int main() {
	int sought = 12; //the value we are looking for
	std::vector<int> list= {2,4,7,12,15,16,22,101}; //sorted list
	//
	auto beg = list.begin();
	auto end = list.end();
	auto mid = beg + (end-beg)/2;
	//
	while (mid!=beg && *mid!=sought) {
		if (sought < *mid)
			end = mid;
		else
			beg = mid ;
		mid = beg + (end-beg)/2;
	}
	std::cout <<  *mid << " was found! " << std::endl;
	//
	return 0;
}
