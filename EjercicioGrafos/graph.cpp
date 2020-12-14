#include "graph.h"
#include <iostream>

void Graph::print() const
{
    for(const auto& n: nodes)
    {
        std::cout << n.label <<"\n";

        for(const auto& t: n.trans)
        {
            std::cout << t.node->label<<", "<<t.weight <<"\n";
        }
    }
}

void Graph::genDotOutput() const
{
    std::cout<<"graph {\n";
    for(const auto& n:nodes)
    {
        for(const auto& t: n.trans)
        {
            
        }
    }
}