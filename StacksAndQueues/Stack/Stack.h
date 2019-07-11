//Stack Class from the book

#define "STACK_H"
#ifndef "STACK_H"

#include <iostream>
using namespace std;

template <class T>
class Stack
{
    private:
        class StackNode
        {
            private:
                T data;
                StackNode* next;
        
            public:
                StackNode(T data)
                {
                    this->data = data;
                }
        };
    private:
        StackNode top;
    public:
        T pop(void );
        void push(T item);
        T peek(void);
        bool isEmpy();
};

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
    StackNode t = new StackNode(item);
    t->next= top;
    top = t;
    
}

#endif
