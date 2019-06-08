//
//
//  Q2.6- Implement a function to check if a linked list is a palindrome
//
//  Created by Hashim Abu Sharkh on 6/3/19.
//  Copyright © 2019 Hashim Abu Sharkh. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"
#include <stack>
using namespace std;

//First thoughts: Can be done by reversing linked list and comparing, the first half of the reversed to the linked list
//Best conceivable run time seems to be o(N) as i will have to at least traverse half the list
//Lets implement then optimize


//Reverse linked list
SinglyLinkedListNode* reverse(SinglyLinkedListNode* node)
{
    SinglyLinkedListNode* head = NULL;
    while(node!=NULL)
    {
        SinglyLinkedListNode* n = new SinglyLinkedListNode(node->data);
        n->next = head;
        head = n;
        node = node->next;
    }
    return head;
    
}

//compare the linkedLists to each other
bool isEqual(SinglyLinkedListNode* first,SinglyLinkedListNode* second)
{
    if(first!=NULL &&second!=NULL)
    {
    if(first->data!=second->data)
        return false;
    
        return isEqual(first->next,second->next);
    }
    return first==NULL && second==NULL;
}
//Use temporary linked list to copy contents, we will have space complexity of O(N) and time complexity of O(n)
bool isPalindrome(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode* tmp = reverse(head);
    return isEqual(head,tmp);
    
}

//I said at the beginning that only half of the linked lists need to be compared, to do that we can use a stack , time complexity will remain at O(n) but will be faster
//If we have the size of the linked list we would iterate over the first half push it to the stack, then continue iterating and compare with the rest of the list
//If we do not know the size we will use the runner technique
//Odd case will have to be handled
bool isPalindromeStack(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode* slow = head,*fast = head;
    
    stack<int> stack;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        stack.push(slow->data);
        slow= slow->next;
        fast = slow->next;
    }
    
    //odd case, middle element will be ignored
    if(fast!=NULL)
        slow = slow->next;
    
    //compare the stack to the rest of the linked list
    while(slow!=NULL)
    {
        if(stack.top()!=slow->data)
            return false;
        slow = slow->next;
        stack.pop();
    }
    
    return true;
    
}

//Last solution is the solution she has for and approached it recursively, i will come back to solve later and understand better

//Test function
int main()
{
    SinglyLinkedList * first = new SinglyLinkedList();
    
    first->appendToTail(1);
    first->appendToTail(0);
    first->appendToTail(1);

    cout<<"Is Linked List a palindrome: "<<isPalindrome(first->head)<<endl;
    
    
    //Test second function (stack)
     cout<<"Is Linked List a palindromeStack: "<<isPalindromeStack(first->head)<<endl;
    
    //Testing recursive approach
    
    free(first->head);
    
    
}


