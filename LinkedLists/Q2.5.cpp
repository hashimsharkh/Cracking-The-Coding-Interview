//Hashim Abu Sharkh
//Q2.5- add two linked lists, that have their digits stored in reverse order   

#include <iostream>
#include "Node.h"
using namespace std;
//AS MENTIONED BEFORE, I SAID I WILL CREATE A LINKED LIST CLASS, THE DAY CAME

//First thought recursion, although expensive, it seems as if it is the easiest choice to go with to be able to implement

//store sum in a new list,need a pointer to store the carry
void addLinkedLists(Node* first,Node* second,Node* newList,int &carry)
{
	if(first==NULL)
		newList->appendToTail(second->getData()+carry);
	if(second==NULL)
		newList->appendToTail(first->getData()+carry);
	if(first==NULL && second==NULL)
		return ;

	if(first->getData()+second->getData()<10)
		newList->appendToTail(first->getData()+second->getData()+carry);
	else 
	{
		carry = first->getData()+second->getData() -10;
		newList->appendToTail(0);
	}
	addLinkedLists(first->getNext(),second->getNext(),newList,carry);
}

void addLinkedLists(Node* first,Node* second,Node*newList)
{
	int carry =0;
	addLinkedLists(first,second,newList,carry);
}
int main()
{
	Node * first = new Node(7);
	first->appendToTail(1);
	first->appendToTail(6);

	Node * second = new Node(5);
	second->appendToTail(9);
	second->appendToTail(2);
	
	Node* newList=new Node(5);

	cout<<"The first linked List is: ";
	first->printLinkedList(first);
	cout<<endl;

	cout<<"The second linked List is: ";
	second->printLinkedList(second);
	cout<<endl;
	//Testing function 

	addLinkedLists(first,second,newList);

	newList->printLinkedList(newList);


	first=NULL;
	second = NULL;
	newList = NULL;
	delete first;
	delete second;
}
