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


bool isCircular(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode* slowRunner=head;
    SinglyLinkedListNode* fastRunner=head;
    
    do{
        if(fastRunner->next==NULL)
            return false;
        slowRunner= slowRunner->next;
        fastRunner = fastRunner->next->next;
        

    }while(slowRunner !=fastRunner);
    return true;
}

int main()
{
    SinglyLinkedList* first = new SinglyLinkedList();
    
    for(int i=1;i<10;i++)
        first->appendToTail(i);
    
    first->tail->next = first->head->next;
    
    cout<<"Is the linked list corrupt? " <<boolalpha<<isCircular(first->head)<<endl;
    
    cout<<"Hello"<<endl;
    
}


