#include <iostream>
#include <sstream>
#include "linked_list.h"

template<typename TElem>
LinkedList<TElem>::LinkedList(const std::initializer_list<TElem>& init)
:head(nullptr),tail(nullptr), size_(0)
{
  for(auto nodo: init)
  {
      pushBack(nodo);
  }
 
}

template<typename TElem>
LinkedList<TElem>::LinkedList(const LinkedList& other)
{
    Node *n=other.head;
    while(n!=nullptr)
    {
        pushBack(n->data);
        n=n->next;
    }
}

template<typename TElem>
LinkedList<TElem>::~LinkedList()
{
    Node* current = head;
    Node* next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

}

//check
template<typename TElem>
void LinkedList<TElem>::pushBack(TElem data)
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

//check
template<typename TElem>
void LinkedList<TElem>::pushFront(TElem data)
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


template<typename TElem>
bool LinkedList<TElem>::operator==(const LinkedList& other) const
{
    return false;
}

