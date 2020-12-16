#ifndef _SORTING_ALG
#define _SORTING_ALG

#include <iostream>
#include <vector>
#include <algorithm>

//Falta Merge Sort y Quick Sort

void cppSort(std::vector<unsigned>& cplusplus)
{

    std::sort(cplusplus.begin(), cplusplus.end());
     
}


void bubbleSort(std::vector<unsigned>& b)
{
    int size = b.size();

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (b[j] > b[j + 1]) {
                int aux = b[j];

                b[j] = b[j + 1];
                b[j + 1] = aux;
            }
        }
    }

}

void insertionSort(std::vector<unsigned>& b)
{
    for(int j = 1; j < b.size(); j++)
    {
      int ins = b[j];
      int i = j-1;

      while(i >= 0 && b[i] > ins)
      {
         b[i+1] = b[i];
         i--;
      }
      b[i+1] = ins;
    }
}


void selectionSort(std::vector<unsigned>& selection)
{
    typedef std::vector<unsigned>::iterator Itr;
    Itr itr = selection.begin();
    
    while(itr != selection.end())
    {
        Itr itr_min = itr;
        for(Itr i = itr + 1; i != selection.end(); i++)
        {
            if(*i < *itr_min)
            {
                itr_min = i;
            }
        }
        std::iter_swap(itr, itr_min);
        itr++;
    }
}

//Heap Sort
void max_heapify(std::vector<unsigned>& arr, int i, int size_)
{
    int largest, l = (2*i) + 1, r = l + 1;

    if(l < size_ && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if(r < size_ && arr[r] > arr[largest])
        largest = r;

    if(largest != i)
    {
        std::swap(arr[i], arr[largest]);
        max_heapify(arr, largest, size_);
    }
}

void build_max_heap(std::vector<unsigned>& arr)
{
    for(int i = (arr.size() / 2); i >= 0; i--)
    max_heapify(arr, i, arr.size());
}


void heapSort(std::vector<unsigned>& arr)
{
   build_max_heap(arr);
   int sz = arr.size();
   for(int i = arr.size() - 1; i > 0; i--)
   {
        std::swap(arr[0], arr[i]);
        sz--;
        max_heapify(arr, 0, sz);
    }
}

#endif