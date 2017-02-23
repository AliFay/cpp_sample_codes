#include <iostream>

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

/*----------------  node struct --------------------*/
struct Node {
	int data;
	int time;
	Node *link; //link to the other elements of the list
};
typedef Node* NodePtr; //pointer to the nodes (same identifications as link)

/*------------  linked list class --------------------*/
class LinkedList {
public:

	LinkedList(); //constructor

	void push(int data, int time); 	//push
	NodePtr pop(); 					//pop
	void remove(int index);			//remove item
	NodePtr search(int target);     //search function
	void remove_duplicates();		//remove duplicates function

	friend std::ostream& operator <<(std::ostream& out, LinkedList& ll);  //overloading the print-out
private:
	NodePtr head;
};

#endif /* LINKEDLIST_H_ */
