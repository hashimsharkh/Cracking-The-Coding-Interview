
//  Q2.5- Sum two linked lists where the digits are stored in reverse order
//
//  Created by Hashim Abu Sharkh on 5/31/19.
//  Copyright © 2019 Hashim Abu Sharkh. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

//First thoughts- Recursion seems the easiest way of doing this but will it be worth it space wise as it will at least take O(N) space
//A linked list will be created to store the numbers anyways
//All i will do is store the carry in a reference pointer(wrapper class  in java )

//Helper function to store the carry
void sumListsReversed(SinglyLinkedListNode * firstHead,SinglyLinkedListNode * secondHead,SinglyLinkedList* llist,int &carry)
{
    if(firstHead==NULL && secondHead==NULL)
    {
        if(carry==0)
            return;
        else
        {
            llist->appendToTail(carry);
            return;
        }
    }
    if(firstHead==NULL)
        llist->appendToTail(secondHead->data+carry);
    if(secondHead==NULL)
        llist->appendToTail(firstHead->data+carry);
    
    if(firstHead->data+secondHead->data+carry<10)
        llist->appendToTail(firstHead->data+secondHead->data+carry);
    else
    {
        llist->appendToTail((firstHead->data+secondHead->data+carry)%10);
        carry =(firstHead->data+secondHead->data+carry)/10;
    }
    
    sumListsReversed(firstHead->next,secondHead->next,llist,carry);
    
}

SinglyLinkedListNode* sumListsReversed(SinglyLinkedListNode * firstHead,SinglyLinkedListNode * secondHead)
{
    int carry =0;
    SinglyLinkedList* llist = new SinglyLinkedList();
    
    sumListsReversed(firstHead,secondHead,llist,carry);
    
    return llist->head;
}

//sum the lists if they were in the same order, just recurse first then do what we did before so that they add in reverse


int main()
{
    SinglyLinkedList * first = new SinglyLinkedList();
    SinglyLinkedList * second = new SinglyLinkedList();
    SinglyLinkedList * result = new SinglyLinkedList();
    
    first->appendToTail(9);
    first->appendToTail(9);
    first->appendToTail(9);
    
    second->appendToTail(5);
    second->appendToTail(9);
    second->appendToTail(2);
    
   result->head = sumLists(first->head,first->head);
    
    cout<<"The Result is: " ;
    printLinkedList(result->head);
}
