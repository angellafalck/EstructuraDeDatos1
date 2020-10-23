#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <initializer_list>

template <typename TElem>

class Array
{
public:
    Array(const std::initializer_list<TElem>& init);
    Array(int size);
    Array(const Array& other)
    {copyFrom(other);}

    ~Array()
    {delete [] arr;}
    
    TElem& operator[](unsigned idx)
    {return arr[idx];}

    Array& operator=(const Array& rhs);

    void print();
    int find(TElem element);
    void sort();
    void insertionSort();
    int findMinIndex(int pos);
    int findMaxIndex(int pos);

    TElem findMinElement()
    {return arr[findMinIndex(0)];}

    TElem findMaxElement()
    {return arr[findMaxIndex(0)];}

    int size() const
    {return size_;}

    private:
    void copyFrom(const Array& other);

private:
    int size_;
    TElem *arr;
};

#include "array.cpp"
#endif