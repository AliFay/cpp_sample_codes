/*
 * linkedList.cpp
 * This is the implementation of the file linkedList.h
 * This is the implementation of the linked list class
 */
#include "linkedList.h"
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <unordered_map>
/*----------linked list implementation --------*/
LinkedList::LinkedList() {
	head = NULL;
}
/*---------------------------------------------*/
void LinkedList::push(int data, int time) {
	//taking care of pointers:
	NodePtr tmpPtr;
	tmpPtr = new Node;
	tmpPtr->link = head; //it is fine if head=NULL

	head = tmpPtr;

	//load the data and time:
	head->data=data;
	head->time=time;
}
/*---------------------------------------------*/
NodePtr LinkedList::pop() {
	NodePtr tmpPtr;
	NodePtr result;
	if (head == NULL) {
		std::cout << "the list is empty";
		return NULL;
	}
	tmpPtr = head;
	head  = tmpPtr-> link;
	//
	result= tmpPtr;
	delete tmpPtr;
	return result;
}
/*---------------------------------------------*/
void LinkedList::remove(int index) {
	NodePtr removePtr;  //remove item
	removePtr = head->link;
	NodePtr beforePtr;  //before item
	beforePtr = head;
	//index 0 corresponds to the head element at the begining of the linked list
	if (index == 0) {
		head = beforePtr-> link;
		delete beforePtr; //removing the  pointer
		return;
	}
	/*----- assigning the pointers ------------*/
	for (int i=2; i<(index+1); i++) {  //finding where to remove
		if (removePtr-> link == NULL) {
			std::cout << "index out of bounds or list is empty!" << std::endl;
			return;
		}
		beforePtr = removePtr;
		removePtr = removePtr-> link;
	}
	/* ----------- removing the item -----------*/
	beforePtr -> link = removePtr-> link;
	delete removePtr; //removing the  pointer
}
/*---------------------------------------------*/
NodePtr LinkedList::search(int target) {
	NodePtr tmpPtr;
	tmpPtr = head;
	//
	if (head == NULL)
		return NULL;
	//
	do{
		if (tmpPtr->data == target)
			return tmpPtr;
		tmpPtr = tmpPtr -> link;

	} while (tmpPtr!=NULL);
	return NULL;
}
/*---------------------------------------------*/
void LinkedList::remove_duplicates(){
	NodePtr currPtr;
	currPtr = head;
	NodePtr prevPtr;
	prevPtr = head;
	NodePtr tmpPtr;

	std::unordered_map<int, bool> items_map; //hash table

	while (currPtr!=NULL) { //iterate through the linked list till reaching NULL
		//
		if (items_map[currPtr->data])  { //if already flagged then it is duplicate
			prevPtr->link=currPtr->link;
			//
			tmpPtr = currPtr;
			delete tmpPtr;
			currPtr = prevPtr->link;
		}
		else
		{
			items_map[currPtr->data]=true;
			prevPtr = currPtr;
			currPtr = currPtr->link;
		}
	}
}
/*---------------------------------------------*/
std::ostream& operator << (std::ostream& out, LinkedList& ll) {
	NodePtr tmpPtr;
	tmpPtr = new Node;
	tmpPtr = ll.head; //make a temp pointer pointing to the after-head

	if (tmpPtr==NULL)  {
		std::cout << "list is empty" << std::endl;
	}
	else {
		do {
			std::cout << "data: " << tmpPtr->data << " at Time: " << tmpPtr->time << std::endl;
			tmpPtr = tmpPtr->link;  //pointing to the next element of the linked list
		} while (tmpPtr != NULL);
		std::cout << std::endl;
	}
}
/*---------------------------------------------*/

