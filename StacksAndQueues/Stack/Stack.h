//Stack Class from the book, altered for C++

#ifndef STACK_H
#define STACK_H


#include <iostream>
using namespace std;



template <class T>
class Stack
{
    private:
        class StackNode
        {
            public:
                T data;
                StackNode* next;
            
                StackNode(T data)
                {
                    this->data = data;
                    next = NULL;
                }
        };
    private:
        StackNode* top;
    public:
        Stack():top(NULL){}
        virtual T pop(void );
        virtual void push(T item);
        T peek(void);
        bool isEmpty(void);

};

//Print stack from top to bottom
template<class T>
void printStack(Stack<T> stack)
{
    if(!stack.isEmpty())
    {
        cout<<stack.peek()<<", ";
        stack.pop();
        printStack(stack);
        
    }
}


template <class T>
T Stack<T>:: pop(void)
{
    if(top == NULL) throw "Empty Stack!";
    T item = top->data;
    top = top->next;
    return item;
}

template <class T>
void Stack<T>:: push(T item)
{
    StackNode *t = new StackNode(item);
    t->next= top;
    top = t;
    
}

template <class T>
bool Stack<T>:: isEmpty(void)
{
    return top == NULL;
}

template<class T>
T Stack<T>:: peek(void)
{
    if(top == NULL) throw "Empty Stack!";
    return top->data;
    
}

        
#endif
