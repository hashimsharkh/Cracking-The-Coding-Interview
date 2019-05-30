//Hashim Abu Sharkh
//Q2.4- Partion a linked list around a value k

#include <iostream>
#include "Node.h"
using namespace std;

//First thoughts- can be done using recursion as problem can be divided into subproblems wiht the expense of at least having a space complexity of O(N) 
//Creating a new linked list


void partition(Node* head,int x,Node* newList)
{
	if(head==NULL)
		return ;

	if(head->getData()<x)
	{	if(newList->getData()==0)
			newList->setData(head->getData());
		else 
			newList->appendToTail(head->getData());
	}
	
	partition(head->getNext(),x,newList);

	if(head->getData()>=x)
	{
		newList->appendToTail(head->getData());
	}
}


int main()
{
	Node * head = new Node(3);
	head->appendToTail(5);
	head->appendToTail(8);
	head->appendToTail(5);
	head->appendToTail(10);
	head->appendToTail(2);
	head->appendToTail(1);

	cout<<"The linked List is: ";
	head->printLinkedList(head);
	cout<<endl;

	//Testing function 
	Node* newList = new Node(0);
	partition(head,5,newList);
	cout<<"The partitioned linked List is: ";
	head->printLinkedList(newList);
	cout<<endl;
}