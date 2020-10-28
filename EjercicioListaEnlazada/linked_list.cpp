#include <iostream>
#include "linked_list.h"

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
              
                std::cout<<"Element found!"<< '\n';
                return n;
            }
           
            n= n->next;
      
    }
    std::cout<<"Element not found!"<< '\n';
    return n;

}

LinkedList::Node* LinkedList::findMin()
{   
    Node* n=head;
    int menor=head->data;
    while(n!=nullptr)
    {
        if(n->data<menor)
        {
            menor=n->data;
        }
        n=n->next;
    }

    std::cout<<"Min: "<<menor<< '\n';
    return n;

}

LinkedList::Node* LinkedList::findMax()
{   
    Node* n=head;
    int mayor=head->data;
    while(n!=nullptr)
    {
        if(n->data>mayor)
        {
            mayor=n->data;
        }
        n=n->next;
    }

    std::cout<<"Max: "<<mayor<< '\n';
    return n;

}