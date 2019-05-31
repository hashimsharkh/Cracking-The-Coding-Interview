#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

//for purposes of solving the questions, this needs to be public otherwise would like to hide this
template<class T>
class Node
{
public:
    Node(T d,Node* n=NULL):data(d),next(n){}
    Node* next;
    T data;
    T inline getData() const {return data;}
};

template<class T>
class LinkedList
{
public:
    LinkedList();//consrtuct an empty linked list
    ~LinkedList();//Destruct a linked list
    unsigned int listSize() const;
    void printLinkedList(Node<T>*);//Helper function to print linked list recursively
    void printLinkedList();//Prints linked list
    bool isEmpty() const;//Checks if a list is empty
    void appendToHead(T );//Adds a node to the head of the list
    void appendToTail(T );//Adds to the end of a tail
    T retrieveHead() const;//Retrieve value of head

private:
    Node<T>* head;
    Node<T>* tail;
    unsigned int size;
};


#endif
