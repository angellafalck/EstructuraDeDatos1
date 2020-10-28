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
        l1.pushBack(i * 20);
    
    l1.print();
    std::cout << '\n';

    std::cout<<"Find Number"<< '\n';
    l1.find(50);

    l1.findMin();
    l1.findMax();

    /*
    for (int i = 10; i >= 1; i--)
    {
        l1.pushFront(i * 10);
        
        l1.print();
        std::cout << '\n';
    }

    l1.print();
    std::cout << '\n';
    */

  

    return 0;
}
