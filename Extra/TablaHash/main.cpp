/*
Tarea funciones Hash: se puede usar std::list o std::forward_list
hacer implementación de conjuntos para enteros e investigar 
para cadenas (listas enlazadas)
Agregar, Eliminar, Buscar, Union e Interseccion
*/

#include <unordered_set>
#include <iostream>

void print(std::unordered_set<int>& l);
std::unordered_set<int> uni(std::unordered_set<int>& l, std::unordered_set<int>& l2);
std::unordered_set<int> inter(std::unordered_set<int>& l, std::unordered_set<int>& l2);
bool find(std::unordered_set<int>& l);

int main()
{
    std::unordered_set <int> nums = {2,4,6};
    std::unordered_set <int> nums2={2,3,7};

    std::cout<<"Hash Table 1: ";
    print(nums);
    std::cout<<"\n";

    std::cout<<"Hash Table 2: ";
    print(nums2);
    std::cout<<"\n";

    std::cout<<"Insert (5) in Hash Table 1: ";
    nums.insert(5);
    print(nums);
    std::cout<<"\n";

    std::cout<<"Erase Number 2 in Table 2: ";
    nums2.erase(2);
    print(nums2);
    std::cout<<"\n";

    std::cout<<"Hash Table 1 Afterwards: ";
    print(nums);
    std::cout<<"\n";
    
    std::cout<<"Hash Table 2 Afterwards: ";
    print(nums2);
    std::cout<<"\n";

    std::cout<<"Find 30: ";
    find(nums);
    std::cout<<"\n";

    std::cout<<"Union: ";
    uni(nums,nums2);
    std::cout<<"\n";

    std::cout<<"Intersection: ";
    inter(nums,nums2);
    std::cout<<"\n";


    return 0;

}

void print(std::unordered_set<int>& l)
{
    std::cout << "[";

    std::unordered_set<int> :: iterator itr; 
    for (itr = l.begin(); itr != l.end(); itr++) 
        std::cout << (*itr) <<" "; 
        
    std::cout << "]";
}

std::unordered_set<int> uni(std::unordered_set<int>& l, std::unordered_set<int>& l2)
{
    std::unordered_set<int> l3=l;

    std::unordered_set<int> :: iterator itr; 
    std::unordered_set<int> :: iterator itr2;
    for (itr = l3.begin(); itr != l3.end(); itr++)
    {
        for(itr2 = l2.begin(); itr2 != l2.end(); itr2++)
        {
            if((*itr2)!=(*itr))
                l3.insert(*itr2);
        }
    } 
    print(l3);
    return l3;
}

std::unordered_set<int> inter(std::unordered_set<int>& l, std::unordered_set<int>& l2)
{
    std::unordered_set<int> l3;

    std::unordered_set<int> :: iterator itr; 
    std::unordered_set<int> :: iterator itr2;
    for (itr = l.begin(); itr != l.end(); itr++)
    {
        for(itr2 = l2.begin(); itr2 != l2.end(); itr2++)
        {
            if((*itr2)==(*itr))
                l3.insert(*itr2);
        }
    } 
    print(l3);
    return l3;
}

bool find(std::unordered_set<int>& l)
{
    std::unordered_set<int>::const_iterator itr = l.find (30);

    if(itr==l.end())
    {
        std::cout<<"Not Found!";
        return true;
    }else
    {
        std::cout<<"Found!";
        return false;
    }
    return false;
}