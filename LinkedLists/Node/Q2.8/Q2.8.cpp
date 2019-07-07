//
//
//  Q2.8- detect the beginning of a loop in a linked list
//
//  Created by Hashim Abu Sharkh on 6/9/19.
//  Copyright © 2019 Hashim Abu Sharkh. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

//First thoughts- can be done using a hash table with additional space complexity O(n).
//However, I think it can be done using additional space of O(1)
//Using the running pointer technique, they will collide at a place, will have to figure out where they collide and if they collide


//Return Node where they collide
SinglyLinkedListNode* isCircular(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode* slowRunner=head;
    SinglyLinkedListNode* fastRunner=head;
    
    do{
        if(fastRunner->next==NULL)
            return NULL;
        slowRunner= slowRunner->next;
        fastRunner = fastRunner->next->next;
        

    }while(slowRunner !=fastRunner);
    return fastRunner;
}

SinglyLinkedListNode* findBeginning(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode* first = head;
    SinglyLinkedListNode* second = isCircular(head);
    if(second==NULL)
        return NULL;
    while(first!=second)
    {
        first = first->next;
        second = second->next;
    }
    return first;
}
int main()
{
    SinglyLinkedList* first = new SinglyLinkedList();
    
    for(int i=1;i<10;i++)
        first->appendToTail(i);
    
    first->tail->next = first->head->next->next->next;
    
    cout<<"Circular Linked List starts at: " <<findBeginning(first->head)->data<<endl;

}


