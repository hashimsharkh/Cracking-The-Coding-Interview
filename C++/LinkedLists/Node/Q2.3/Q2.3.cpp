//Hashim Abu Sharkh
//Q2.3- delete a middle node
//Delete a specific node based on input (not first or last) given only access to that node

#include <iostream>

using namespace std;

//Implenentation of Node before creation of linked list class
class Node
{
private:
    Node* next;
    int data;
    
public:
    
    Node(int d,Node* n=NULL):data(d),next(n){}
    
    void appendToTail(int );
    
    void printLinkedList(Node* );
    
    int getData() const;
    
    Node* getNext() const;
    
    void setNext(Node * );
    
    void setData(int );
    
};

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
void Node:: appendToTail(int d)
{
    Node* end = new Node(d);
    
    Node *n=this;
    
    while(n->next!=NULL)
        n=n->next;
    n->next=end;
    n->next->next=NULL;
    
    end = NULL;
    delete end;
}

void Node:: printLinkedList(Node* head)
{
    if(head!=NULL)
    {
        std::cout<<head->getData()<<" ";
        printLinkedList(head->getNext());
    }
}

int Node:: getData() const
{
    return data;
}

Node* Node:: getNext() const
{
    return next;
}

void Node:: setNext(Node * n)
{
    next = n;
}

void Node:: setData(int data)
{
    this->data=data;
}

