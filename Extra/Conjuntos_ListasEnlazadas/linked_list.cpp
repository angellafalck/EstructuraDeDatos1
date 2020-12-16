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

template<typename TElem>
void LinkedList<TElem>::Union(const LinkedList<TElem> l1, const LinkedList<TElem>  l2)
{
    head=nullptr;
    Node* newn1= l1.head;
    Node* newn2= l2.head;

    while(newn1!=nullptr)
    {
        pushBack(newn1->data);
        newn1= newn1->next;
    }

    while(newn2!=nullptr)
    {
        if(buscar(newn2->data)==-1)
        {
            pushBack(newn2->data);
        }
        
    newn2= newn2->next;
    }

}

template <typename TElem>
TElem LinkedList<TElem>::buscar(TElem num)
{
    Node* aux = head;
    while(aux != nullptr)
    {
        if(aux->data == num)
            return num;

        aux = aux->next;
    }

    return -1;
}

template <typename TElem>
bool LinkedList<TElem>::find(TElem num)
{
    Node* aux = head;
    while(aux != nullptr)
    {
        if(aux->data == num)
            return true;

        aux = aux->next;
    }

    return false;
}

template<typename TElem>
void LinkedList<TElem>::Interseccion(const LinkedList<TElem> l1, const LinkedList<TElem> l2)
{
    head = nullptr;
    Node* newn1 = l1.head;
    Node* newn2;
    while(newn1 != nullptr)
    {
        newn2 = l2.head;
        while(newn2 != nullptr)
        {
            if(newn1->data == newn2->data)
            {
                pushBack(newn1->data);
                break;
            }

            newn2 = newn2->next;
        }

        newn1= newn1->next;
    }
}
template<typename TElem>
void LinkedList<TElem>::eliminar(TElem num)
{
    Node* newn = head;
    Node* prev = nullptr;

    if (newn != nullptr && newn->data == num)
    {
        head = newn->next;
        delete newn;
        return;
    }

    while (newn != nullptr && newn->data != num)
    {
        prev = newn;
        newn = newn->next;
    }

    if (newn == nullptr)
        return;

    prev->next = newn->next;

    delete newn;
}

template<typename TElem>
void LinkedList<TElem>::print() const
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
