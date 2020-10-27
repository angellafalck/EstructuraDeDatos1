#include <iostream>
#include <vector>
#include <algorithm>


template<typename T>
std::ostream& operator <<(std::ostream& out, const std::vector<T>&arr)
{
    std::cout <<"[ ";
    bool first=true;
    for(auto& elem: arr)
    {
        if (first) first=false;
        else std::cout <<", ";

        std::cout<<elem;
    }
    std::cout<<" ]";

    //Ejemplo de como era antes
    /*
    for(typename std::vector<T>::const_iterator it = arr.begin(); it != arr.end(); it++)
    {
        if (first) first=false;
        else std::cout <<", ";

        std::cout<<*it;
    }
    */

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
    std::vector<int> arr({59,13,46,9,33,55,15,79,92,6,46});
    std::vector<int> arr2;
    std::vector<int>arr3(arr);


    std::cout<<"Array 1\n"
            <<arr<<"\n\n";
    arr2= arr;
    for(int i=10; i<=100; i+=10)
    {
        arr.push_back(i);
    }
    
    std::cout<<"Array 1\n"
            <<arr<<"\n\n";

    std::cout<<"Array 2\n"
            <<arr2<<"\n\n";

    std::cout<<"Array 3\n"
            <<arr3<<"\n\n";

    auto it= std::find(arr.begin(), arr.end(), element);

    if(it != arr.end())
        std::cout<<element<<" is at position "<<(std::distance(arr.begin(), it))<<'\n';
    else
        std::cout<<"Cannot find element in array "<<'\n';


    std::cout<<'\n'<<"Sort"<<'\n';
    std::sort(arr.begin(), arr.end(),[](int a, int b){return a>b;});
    std::cout<<arr<<"\n'\n'";


    return 0;
    
}
