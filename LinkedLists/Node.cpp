#include "Node.h"


void Node::appendToTail(int d)
{
	Node* end = new Node(d);

	Node *n=this;

	while(n->next!=NULL)
		n=n->next;
	n->next=end;
	n->next->next=NULL;
}