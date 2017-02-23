/*
 *
 *  Created on: Jan, 2017
 *      Author: S. Ali Reza Fayazi
 */
#include <iostream>
#include "linkedList.h"
/*----------------  main -----------------------*/
int main() {
	int search_value =10;
	LinkedList llist;  //make the linked list

	llist.push(5, 1000); //push random data into the stack
	llist.push(5, 4000);
	for (int i=0; i<10; i++) {  //populate the list with random 1 to 10 (as an example)
		llist.push(rand() % 10 + 1, i*1000); //rand() % 10 + 1
	}

	std::cout << "The original stack is: " << std::endl;
	std::cout << llist;  //print out the list

	std::cout << "The stack with data unique values is: " << std::endl;
	llist.remove_duplicates();
	std::cout << llist;  //print out the list

	NodePtr tmpPtr = llist.search(search_value);
	if (tmpPtr!=NULL)
		std::cout << "Searched for " <<  search_value << " and found it with time:" << tmpPtr->time << std::endl;
	else
		std::cout << "Searched for " <<  search_value << " but not found!" << std::endl;

	return 0;
}
