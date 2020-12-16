#ifndef _STACK_H
#define _STACK_H

template <typename TElem> 

class Stack
{
public:
    class Node
    {
    public:
        Node(TElem val)
        : data(val), next(nullptr)
        {}
        
        TElem data;
        Node *next;
    };

    Stack()
    : top(nullptr)
    {}

    Stack(const std::initializer_list<TElem>& init)
    {
        for(auto nodo: init)
        {
            push(nodo);
        }
    }
    Stack(const LinkedList& other);

    ~Stack()
    {}

    std::string toString() const;
    void push(TElem data);
    void pop();
    int size;
   
private:
    Node *top;
};

template<typename T>
std::ostream& operator << (std::ostream& out, const Stack<T>& data)
{
    data.toString();
    return out;
}

#include "stack.cpp"

#endif
