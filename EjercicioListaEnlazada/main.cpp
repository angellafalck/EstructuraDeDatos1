#include <iostream>
#include "linked_list.h"

int main(int argc, char *argv[])
{
    /*if (argc != 2)
    {
        std::cerr << "usage: " << argv[0] << " <element>\n";
        return 1;
    }
    int element = std::strtol(argv[1], nullptr, 10);*/

    LinkedList l1;

    l1.print();
    std::cout << '\n';
    

    for (int i = 1; i <= 10; i++)
        l1.pushBack(i * 50);
    
    
    l1.print();
    std::cout << '\n';

    std::cout<<"List size: "<<l1.size()<<'\n';

        for (int i = 10; i >= 1; i--)
    {
        l1.pushFront(i * 10);
        
        l1.print();
        std::cout << '\n';
    }

    l1.print();
    std::cout << '\n';

    std::cout<<"List size: "<<l1.size()<<'\n';

    int elem=0;
    std::cin>>elem;
    if(l1.find(elem)==nullptr)
    {
        std::cout<<"Element not found "<< '\n';
        std::cout<<"Maximum: "<<l1.findMin()->data<<'\n';
        std::cout<<"Minimum: "<<l1.findMax()->data<<'\n';
    }else
    {
        std::cout<<"Element found "<< '\n';
        std::cout<<"Maximum: "<<l1.findMin()->data<<'\n';
        std::cout<<"Minimum: "<<l1.findMax()->data<<'\n';
    }
  


    return 0;
}
