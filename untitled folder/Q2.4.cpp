//Hashim Abu Sharkh
//Q2.4- Partion a linked list around a value k

#include <iostream>
#include "LinkedList.h"
using namespace std;

//First thoughts- can be done using recursion as problem can be divided into subproblems wiht the expense of at least having a space complexity of O(N) 
//Creating a new temporary linked list which will store the items is a must, creating two would allow the items to stay in their relative items
//The whole idea is the same as if it were to be done in real life, scan through the linked list, add the items less than the value to the head of the list, the items bigger to
//the tail


//This was created before creation of linked list class
void partition(SinglyLinkedListNode* head,int x,SinglyLinkedList* newList)
{
	if(head==NULL)
		return ;

	if(head->data<x)
        newList->appendToTail(head->data);
	
	partition(head->next,x,newList);

	if(head->data>=x)
		newList->appendToTail(head->data);
	
}



int main()
{
    SinglyLinkedList * llist = new SinglyLinkedList();

    int llistCount;
    cout<<"How many items do you want to have in the list? "<<endl;
    cin>>llistCount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout<<"What integers do you want to have in your list?"<<endl;
    for(int i=0;i<llistCount;i++)
    {
        int llistItem;
        cin>>llistItem;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        llist->appendToTail(llistItem);
    }
    
    cout<<"Print the Linked List: \n";
    printLinkedList(llist->head);
    cout<<endl;
    
    cout<<"What Number do you want to partition it at: "<<endl;
    int partitionInput;
    cin>>partitionInput;
    
    SinglyLinkedList * tempList = new SinglyLinkedList();
    
    partition(llist->head,partitionInput,tempList);
    
    cout<<"Print the Partitioned Linked List: "<<endl;
    printLinkedList(tempList->head);
    cout<<endl;
    
    free_singly_linked_list(llist->head);
    free_singly_linked_list(tempList->head);
    
}
