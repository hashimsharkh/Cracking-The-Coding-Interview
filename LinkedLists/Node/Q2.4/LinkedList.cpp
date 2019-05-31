//
//  main.cpp
//  Node
//
//  Created by Hashim Abu Sharkh on 5/31/19.
//  Copyright © 2019 Hashim Abu Sharkh. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

template<class T>
void LinkedList<T>:: appendToTail(T d)
{
    if(isEmpty())
        appendToHead(d);
    else
    {
        tail = tail->next = new Node(d);
        size++;
    }
}
template<class T>
Node* LinkedList<T>::retrieveHead() const
{
    return head;
}
template<class T>
void LinkedList<T>:: appendToHead(T d)
{
    head = new Node(d,head);
    if(tail==NULL)
        tail = head;
    size++;
}

//Helper function
template <class T>
void LinkedList<T> :: printLinkedList(Node* head)
{
    if(head!=NULL)
    {
        std::cout<<head->data<<" ";
        printLinkedList(head->getNext());
    }
    
}


template <class T>
void LinkedList<T> :: printLinkedList()
{
    printLinkedList(head);
}

template <class T>
LinkedList<T>::LinkedList():head(NULL),tail(NULL),size(0){}

template<class T>
LinkedList<T>::~LinkedList()
{
    Node* current = head,nextNode;
    
    while(current!=NULL)
    {
        nextNode = current->next;
        
        
        delete current;
        
        current = nextNode;
    }
}

template <class T>
unsigned int LinkedList<T> ::size() const
{
    return size;
}

template <class T>
bool LinkedList<T> :: isEmpty()
{
    return !size;//If size = 0 , return true,else false
}
