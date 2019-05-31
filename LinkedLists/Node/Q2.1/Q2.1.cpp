//Linked Lists
//Q2.1- Remove duplicates from an unsorted linked list

#include <iostream>
#include <unordered_set>
#include<iterator>
#include "Node.h"
using namespace std;

//Can be done recursively, takes up O(n) space, can also be done iteratively
//As I have been writing for nearly all the solutions, hash map are always on the back of my mind and might help to solve
//I will use the simple Node definition in the book (placed in Node.h), I will also implement a singly linked list class later on to make my life easier

//Implementation of Node
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

//Time complexity of O(n) with a temporary buffer
void removeDuplicates(Node* head)
{
    
    unordered_set<int> myMap;
    
    Node* previous = NULL;
    
    while(head!=NULL)
    {
        
        if(myMap.count(head->getData())>0)
        {
            
            previous->setNext(head->getNext());
        }
        else
        {
            myMap.insert(head->getData());
            previous = head;
        }
        
        head=head->getNext();
    }
    
}

//without a temporary buffer, the running technique will be used
//O(n^2) time complexity as were iterating through the list twice but O(1) space
void removeDuplicates1(Node* head)
{
    Node* current=head;
    
    while(current!=NULL)
    {
        
        Node* runner=current;
        
        while(runner->getNext()!=NULL)
        {
            if(current->getData()==runner->getNext()->getData())
                runner->setNext(runner->getNext()->getNext());
            else
                runner=runner->getNext();
            
        }
        current=current->getNext();
    }
}
int main()
{
    //Testing first function
    
    Node * head = new Node(5);
    
    head->appendToTail(8);
    head->appendToTail(5);
    head->appendToTail(5);
    head->appendToTail(3);
    
    head->printLinkedList(head);
    
    cout<<endl;
    removeDuplicates(head);
    
    head->printLinkedList(head);
    head=NULL;
    
    delete head;
    cout<<endl;
    
    //Testing second function
    
    head = new Node(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(3);
    head->printLinkedList(head);
    
    cout<<endl;
    removeDuplicates1(head);
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
