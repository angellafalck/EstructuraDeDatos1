/*
Tarea 2: Implementación de Conjuntos con Listas Enlazadas
Agregar, Eliminar, Buscar, Unión e Intersección
*/

#include <iostream>
#include "linked_list.h"


int main()
{
   
    LinkedList<int> l1;
    LinkedList<int> l2;
    LinkedList<int> l3;
    LinkedList<int> l4;

    l1.print();
    std::cout << '\n';
    

    for (int i = 1; i <= 10; i++)
        l1.pushBack(i * 50);
    
    for (int i = 1; i <= 10; i++)
        l2.pushBack(i * 20);

   
    std::cout <<"\nLista 1:\n";
    l1.print();

    std::cout <<"\nLista 2:\n";
    l2.print();

    l3.Union(l1,l2);
    std::cout <<"\nLista Union:\n";
    l3.print();

    std::cout <<"\nLista Inteserccion:\n";
    l4.Interseccion(l1,l2);
    l4.print();

    std::cout <<"\nBuscar Elemento 300:\n";
    if(l1.find(300)==true)
    {
        std::cout<<"Encontrado\n";
    }else
    {
        std::cout<<"No existe\n";
    }
    

    std::cout <<"Agregar Elemento 500:\n";
    l1.pushBack(600);
    l1.print();

    std::cout<<"\nEliminar Elemento 300:\n";
    l1.eliminar(300);
    l1.print();
    return 0;
}