#include "../Stack/Stack.h"


#Q3.3, Implement a class which which will create a new stack everytime a previously created class reaches it's capacity

template <class T>
class SetOfStacks: public Stack
{
    private:
        int capacity;
        int size;
    public:
    SetOfStacks(int capacity)
    {
        this->capacity = capacity;
        size = 0;
    }
    void push(T element)
    {
        
    }
};


int main()
{
    Stack<int> emak;
    emak.push(5);
    emak.push(7);
    
    printStack(emak);
    
}
