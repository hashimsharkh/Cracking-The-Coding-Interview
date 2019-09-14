//
//
//  Q2.7-Find intersection between two linked lists
//
//  Created by Hashim Abu Sharkh on 6/8/19.
//  Copyright © 2019 Hashim Abu Sharkh. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"
//First thoughts using a hashmap to check for duplicates,however with the expense of having O(n) additional space
//Read the first hint: it says it can be done using O(1) additional space and O(A+B) time (similar to hash map)

//Using that information, if I traverse the two linked lists and compare their tails, if they are identical then the two linked lists intersect
//However, I need to find where they intersect, lets start by finding the size and the tails

//A class is needed to get both value
class Result
{
public:
    SinglyLinkedListNode* tail;
    int size;
    Result(SinglyLinkedListNode* tail=NULL, int size=0):tail(tail),size(size){}
};

//Get tail and size
Result getTailAndSize(SinglyLinkedListNode* head)
{
    Result result;
    while(head->next!=NULL)
    {
        result.size++;
        head = head->next;
    }
    result.tail = head;
    result.size++;
    return result;
}

SinglyLinkedListNode* getKthNode(SinglyLinkedListNode* head, int k)
{
    SinglyLinkedListNode* current = head;
    
    for(int i=0;i<k;i++)
    {
        current = current->next;
        if(current ==NULL)
            return NULL;
    }
    return current;
}

SinglyLinkedListNode*findIntersection(SinglyLinkedListNode*first,SinglyLinkedListNode*second)
{
    Result result1 = getTailAndSize(first);
    Result result2 = getTailAndSize(second);
    
    if(result1.tail!=result2.tail)
        return NULL;
    //Set pointers to each of the linked lists
    SinglyLinkedListNode* shorter = result1.size<result2.size?first:second;
    SinglyLinkedListNode* longer = result1.size<result2.size?second:first;
    
    //Advance the longer linked list by difference in lengrhts
    longer = getKthNode(longer,abs(result1.size-result2.size));
    
    
    //move both pointers until you find the intersection
    while(shorter!=longer)
    {
        shorter = shorter->next;
        longer = longer->next;
    }
    
    //return either one
    return longer;
    
    
}

int main(int argc, const char * argv[]) {
    SinglyLinkedList * first = new SinglyLinkedList();
    SinglyLinkedList* second = new SinglyLinkedList();
    
    first->appendToTail(1);
    first->appendToTail(0);
    first->appendToTail(1);
    
    second->appendToTail(7);
    second->appendToTail(2);
    second->appendToTail(3);
    second->head->next->next->next =first->head->next;
    second->tail = first->tail;
    
    //Test function
    
    SinglyLinkedListNode* result = findIntersection(first->head,second->head);
    
    //should be 0
    cout<<"The data of the intersecting node is: "<<result->data<<endl;
    
    free(first->head);
    free(second->head);
}
