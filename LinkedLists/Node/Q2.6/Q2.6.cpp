//
//
//  Q2.6- Implement a function to check if a linked list is a palindrome
//
//  Created by Hashim Abu Sharkh on 6/3/19.
//  Copyright © 2019 Hashim Abu Sharkh. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

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

//I said at the beginning that only half of the linked lists need to be compared, to do that we can use a stack if we have the size, time complexity will remain at O(n) but will be faster
//Test function
int main()
{
    SinglyLinkedList * first = new SinglyLinkedList();
    
    first->appendToTail(1);
    first->appendToTail(0);
    first->appendToTail(1);

    cout<<"Is Linked List a palindrome: "<<isPalindrome(first->head)<<endl;
    
    free(first->head);
}


