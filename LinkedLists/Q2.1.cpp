//Linked Lists
//Q2.1- Remove duplicates from an unsorted linked list

#include <iostream>
using namespace std;

//Can be done recursively, takes up O(n) space, can also be done iteratively
//As I have been writing for nearly all the solutions, hash map are always on the back of my mind and might help to solve
//I will use the simple Node definition in the book 

class Node
{
	private:
	Node* next;
	int data;

	public:
	Node(int d,Node* n=NULL):data(d),next(n){}

};