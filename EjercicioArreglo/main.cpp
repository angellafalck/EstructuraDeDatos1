#include <iostream>
#include "array.h"
#include <array>
#include <algorithm>


template<typename T, size_t size>
std::ostream& operator <<(std::ostream& out, const std::array<T, size>& arr)
{
    std::cout <<"[ ";
    bool first=true;
    for(int i=0; i<size;i++)
    {
        if (first) first=false;
        else std::cout <<", ";

        std::cout<<arr[i];
    }
    std::cout<<" ]";
    return out;
}


int main(int argc, char*argv[])
{
   
    if(argc!=2)
    {
        std::cerr<<"usage: "<<argv[0]<<" <element>"<<'\n';
        return 1;
    }

    int element= std::strtol(argv[1], nullptr, 10);
    //Array<int> arr....
    std::array<int,11> arr({59,13,46,9,33,55,15,79,92,6,46});
    std::array<int,11> arr2;
    std::array<int,11>arr3(arr);

    arr2= arr;
    
    std::cout<<"Array 2\n";
    //arr2.print();
    std::cout<<arr2<<'\n';
    std::cout<<'\n';

    std::cout<<"Array 3\n";
    //arr3.print();
    std::cout<<arr3<<'\n';
    std::cout<<'\n';

    auto it= std::find(arr.begin(), arr.end(), element);
    //int idx= arr.find(element);

    if(it != arr.end())
        std::cout<<element<<" is at position "<<(std::distance(arr.begin(), it))<<'\n';
    else
        std::cout<<"Cannot find element in array "<<'\n';


    std::cout<<'\n';
    std::cout<<"Sort"<<'\n';
    std::sort(arr.begin(), arr.end(),[](int a, int b){return a>b;});
    //arr.print();
    std::cout<<arr<<'\n';
    std::cout<<'\n';

    //SIn usar
/*
     std::cout<<"Insertion Sort"<<'\n';
    arr.insertionSort();
    arr.print();
    std::cout<<arr<<'\n';

    int min= arr.findMinIndex(0);
    std::cout <<"Minimum is at position: "<<min<<'\n';
    int max= arr.findMaxIndex(0);
    std::cout <<"Maximum is at position: "<<max<<'\n';

    std::cout<<"Array 2"<<'\n';
    //arr2.print();
    std::cout<<arr2<<'\n';
    std::cout<<'\n';

    Array<double> arrd({0.4545, 3.14159, 3.12, 0.004});
    Array<std::string> arrs({"juan", "pedro", "maria", "ana"});

    std::cout<<"String array\n";
    arrs.sort();
    //arrs.print();
    std::cout<<arrs<<'\n';
    std::cout<<"\n";
    std::cout<<"Insertion Sort"<<'\n';
    arrs.insertionSort();
    //arrs.print();
    std::cout<<arrs<<'\n';
    std::cout<<'\n';

    std::cout<<"Double array\n";
    arrd.sort();
    //arrd.print();
    std::cout<<arrd<<'\n';
    std::cout<<"\n";
    */

    return 0;
    
}

