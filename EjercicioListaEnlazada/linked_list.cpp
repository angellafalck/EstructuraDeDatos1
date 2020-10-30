#include <iostream>
#include "linked_list.h"

std::ostream& operator << (std::ostream& out, const LinkedList& lst)
{
    lst.print();
    return out;
}

int LinkedList::size() const
{
    Node *n = head;
    int sz = 0;
    while (n != nullptr)
    {
        sz++;
        n = n->next;
    }

    return sz;
}

void LinkedList::pushBack(int data)
{
    Node *newn = new Node(data);
    if (head == nullptr)
    {
        head = tail = newn;
    }
    else
    {
        tail->next = newn;
        tail = newn;
    }
}

void LinkedList::pushFront(int data)
{
    Node *newn = new Node(data);
    if (head == nullptr)
    {
        head = tail = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
}

void LinkedList::print() const
{
    std::cout << "[ ";
    bool first = true;

    Node *n = head;
    while (n != nullptr)
    {
        if (first) first = false;
        else std::cout << ", ";

        std::cout << n->data;
        n = n->next;
    }
    std::cout << " ]";
}

LinkedList::Node* LinkedList::find(int elem)
{
    Node* n=head;

    while(n!=nullptr)
    {   
           if(n->data==elem)
            {
                return n;
            }
           n= n->next;
    }
    return nullptr;

}

LinkedList::Node* LinkedList::findMin()
{   
    Node* n=head;
    Node* menor=head;
    while(n!=nullptr)
    {
        if(n->data<menor->data)
        {
            menor=n;
        }
        n=n->next;
    }
    return menor;
}

LinkedList::Node* LinkedList::findMax()
{   
    Node* n=head;
    Node* mayor=head;
    while(n!=nullptr)
    {
        if(n->data>mayor->data)
        {
            mayor=n;
        }
        n=n->next;
    }
    return mayor;
}

