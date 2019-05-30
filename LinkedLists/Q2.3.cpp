//Hashim Abu Sharkh
//Q2.3- delete a middle node
//Delete a specific node based on input (not first or last) given only access to that node

#include <iostream>
#include "Node.h"

using namespace std;

//First thoughts:
//I am only given access to the middle node
//So the only way I can do this logically is by making it appear somehow as if i made the previous node point to the next node
//This can be done by copying the data from the next node over to the current node
//then deleting next node
//If middle is the last node, then this problem is not possible
void deleteMiddleNode(Node* middle)
{
	if(middle==NULL || middle->getNext()==NULL)
		return ;

	Node* next = middle->getNext();
	int nextData = next->getData();
	middle->setData(nextData);
	middle->setNext(next->getNext());
	next->setNext(NULL);

}

int main()
{

	Node * head = new Node(5);
	head->appendToTail(8);
	head->appendToTail(5);
	head->appendToTail(5);
	head->appendToTail(3);

	cout<<"The linked List is: ";
	head->printLinkedList(head);
	cout<<endl;

	//Testing function 
	//Delete second node
	deleteMiddleNode(head->getNext());

	//print linked list
	cout<<"The modified linked List is: ";
	head->printLinkedList(head);
	cout<<endl;

	head=NULL;

	delete head;
}
