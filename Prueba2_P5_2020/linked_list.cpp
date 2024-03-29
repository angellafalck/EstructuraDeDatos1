#include <iostream>
#include <sstream>
#include "linked_list.h"

template<typename TElem>
LinkedList<TElem>::LinkedList(const std::initializer_list<TElem>& init)
:head(nullptr),tail(nullptr)
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

template<typename TElem>
int LinkedList<TElem>::size() const
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
std::string LinkedList<TElem>::toString() const
{
    std::ostringstream out;
    
    out << "[";
    bool first = true;

    Node *n = head;
    while (n != nullptr)
    {
        if (first) first = false;
        else out << ",";

        out << n->data;
        n = n->next;
    }
    out << "]";
    
    return out.str();
}

template<typename TElem>
bool LinkedList<TElem>:: isSorted() const
{
    Node *n = head;
    Node *nod=head->next;
    while(nod!=nullptr)
    {
        if(n->data>nod->data)
        return false;

        nod=nod->next;
        n=n->next;
    }
    return true;

return false;
}

//Selection sort
template<typename TElem>
void LinkedList<TElem>::sort()
{
  Node* newn = head;

    while(newn!=nullptr)
    {
        Node* min=newn;
        Node* aux=newn->next;

        while(aux!=nullptr)
        {
            if(aux->data < min->data)
            min=aux;

        aux=aux->next;
        }

        int temp= newn->data;
        newn->data= min->data;
        min->data=temp;
        newn=newn->next;
        
    }

}
