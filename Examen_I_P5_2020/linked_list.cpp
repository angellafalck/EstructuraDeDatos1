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
LinkedList<TElem>:: LinkedList(const std::vector<TElem>& v)
:head(nullptr),tail(nullptr), size_(0)

{
    for(TElem jeje: v)
    {
        pushBack(jeje);
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
     size_++;
}


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
     size_++;
}


template<typename TElem>
bool LinkedList<TElem>::operator==(const LinkedList& other) const
{
    Node* first= head;
    Node* second=other.head;

    if((first==nullptr || second ==nullptr) || size() != other.size())
        return false;

    while(first!=nullptr && second!=nullptr)
    {
        if(first->data != second->data)
            return false;

        first = first->next;
        second = second->next;
    }
  
    return true;
}

template<typename TElem>
bool LinkedList<TElem>::operator==(const std::vector<TElem>& other) const
{
    Node *first= head;
    
    if((first==nullptr || other.empty() )|| size() !=other.size())
    return false; 

    for(auto& elem:other)
    {
        if(first->data != elem)
            return false;

        first=first->next;
    }
  
    return true;
}
