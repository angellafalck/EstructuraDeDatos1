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
    for (int i = 0; i < selection.size(); i++)
    {
        int min = i;
        for (int j = i + 1; j < selection.size(); j++)
        {
            if (selection[j] < selection[min])
                min = j;
        }
        
        int temp = selection[i];
        selection[i] = selection[min];
        selection[min] = temp;
    }
}

void quickSortRec(std::vector<unsigned>& numeros, int izq, int der)
{
    int i = izq;
    int j = der;
    int pivote = numeros[(izq + der) / 2];
    int auxiliar;

    do
    {
        while(numeros[i] < pivote && i < der)
            i++;

        while(pivote < numeros[j] && j > izq)
            j--;

        if(i <= j)
        {
            auxiliar = numeros[i];
            numeros[i] = numeros[j];
            numeros[j] = auxiliar;
            i++;
            j--;
        }
    }while(i <= j);

    if(izq < j)
        quickSortRec(numeros, izq, j);
    
    if(der > i)
        quickSortRec(numeros, i, der);
}

void quickSort(std::vector<unsigned>& numeros)
{
    quickSortRec(numeros, 0, numeros.size() - 1);
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

void merge(std::vector<unsigned> &vec, int start, int middle, int end) 
{
    std::vector<unsigned> leftVec(middle - start + 1);
    std::vector<unsigned> rightVec(end - middle);

    // fill in left Vec
    for (int i = 0; i < leftVec.size(); ++i)
        leftVec[i] = vec[start + i];

    // fill in right Vec
    for (int i = 0; i < rightVec.size(); ++i)
        rightVec[i] = vec[middle + 1 + i];

    /* Merge the temp Vecs */

    // initial indexes of first and second subVecs
    int leftIndex = 0, rightIndex = 0;

    // the index we will start at when adding the subVecs back into the main Vec
    int currentIndex = start;

    // compare each index of the subVecs adding the lowest value to the currentIndex
    while (leftIndex < leftVec.size() && rightIndex < rightVec.size()) {
        if (leftVec[leftIndex] <= rightVec[rightIndex]) {
            vec[currentIndex] = leftVec[leftIndex];
            leftIndex++;
        } else {
            vec[currentIndex] = rightVec[rightIndex];
            rightIndex++;
        }
        currentIndex++;
    }

    while (leftIndex < leftVec.size())
        vec[currentIndex++] = leftVec[leftIndex++];

    while (rightIndex < rightVec.size()) 
        vec[currentIndex++] = rightVec[rightIndex++];
}

void mergeSort2(std::vector<unsigned> &arr, int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;

        mergeSort2(arr, start, middle);
        mergeSort2(arr, middle + 1, end);

        merge(arr, start, middle, end);
    }
}

void mergeSort(std::vector<unsigned>& vec)
{
    mergeSort2(vec, 0, vec.size() - 1);
}



#endif