#ifndef NODE_H
#define NODE_H

#include <iostream>


class Node
{
	private:
	Node* next;
	int data;

	public:
	Node(int d,Node* n=NULL):data(d),next(n){}


	void appendToHead(int);
	void appendToTail(int d)
	{
		Node* end = new Node(d);

		Node *n=this;

		while(n->next!=NULL)
			n=n->next;
		n->next=end;
		n->next->next=NULL;
	}

	void printLinkedList(Node* head)
	{
		if(head!=NULL)
		{
			std::cout<<head->getData()<<" ";
			printLinkedList(head->getNext());
		}
	}

	int getData()
	{
		return data;
	}

	Node* getNext()
	{
		return next;
	}

	void setNext(Node * n)
	{
		next = n;
	}

	void setData(int data)
	{
		this->data=data;
	}
};

#endif