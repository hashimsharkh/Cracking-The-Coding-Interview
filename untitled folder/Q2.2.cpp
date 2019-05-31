#include <iostream>
#include "Node.h"
using namespace std;
//Q2.2 - Return kth to last element

//If size is known, just iterate with a pointer until length-k, time Complexity O(N), space Complexity (O(1)) 




//If size is unknown
//we can compute the size of the linked list in O(n) runtime then iterate
//Iterative
Node* kthToLastElement(Node* head,int k)  
{
	Node * current = head;
	int size =0;

	while(current!=NULL)
	{
		size++;
		current=current->getNext();
	}

	for(int i=1;i<size-k;i++)
		head=head->getNext();
	return head; 
}

//Printing kthToLastElement recursive approach, uses O(n) space
int printKthToLastElement(Node* head,int k)
{
	if(head==NULL)
		return 0;
	int result = printKthToLastElement(head->getNext(),k)+1;
	if(k==result)
		cout<<"The "<<k<<"nd to last node is: "<<head->getData()<<endl;
	return result;

}
//Recursive approach using pointer 
Node* kthToLastElementR(Node* head,int k, int &i)
{
	if(head==NULL)
		return NULL;
	Node* result = kthToLastElementR(head->getNext(),k,i);
	i=i+1;
	if(i==k)
		return head;
	
	return result;

	
}
Node *kthToLastElementRecursive(Node* head,int k)
{
	int i=0;
	return kthToLastElementR(head,k,i);
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

	//Testing first function 
	cout<<"The Last Node is: "<<kthToLastElement(head,0)->getData()<<endl;
	
	//Testing second function 
	printKthToLastElement(head,2);

	//Testing third function 
	cout<<"The 4th to Last Node is: "<<kthToLastElementRecursive(head,4)->getData()<<endl;

	head->printLinkedList(head);
	cout<<endl;
	head=NULL;

	delete head;

}