#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_


template <typename TElem> 

class LinkedList
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

    LinkedList()
    : head(nullptr), tail(nullptr)
    {}

    LinkedList(const std::initializer_list<TElem>& init);
    
    int size() const;
    void pushBack(TElem data);
    void pushFront(TElem data);

    void sort();

    //TAREA CONJUNTOS
    void Union(const LinkedList<TElem> l1, const LinkedList<TElem> l2);
    void Interseccion(const LinkedList<TElem> l1, const LinkedList<TElem> l2);
    void eliminar(TElem num);
    TElem buscar(TElem num);
    bool find(TElem num);
    void print() const;
   
private:
    Node *head;
    Node *tail;
};

template<typename T>
std::ostream& operator << (std::ostream& out, const LinkedList<T>& data)
{
    data.toString();
    return out;
}

#include "linked_list.cpp"
#endif
  