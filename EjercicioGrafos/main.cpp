#include <iostream>
#include "graph.h"

int main()
{
    Graph g;

    Graph::Node na("A");
    Graph::Node nb("B");
    Graph::Node nc("C");
    Graph::Node nd("D");
    Graph::Node ne("E");


    //Node A
    na.addTrans(&nb,100);
    na.addTrans(&nc,10);
    na.addTrans(&nd,5);

    //Node B
    nb.addTrans(&na,100);
    nb.addTrans(&nc,20);
    nb.addTrans(&ne,100);

    //Node C
    nc.addTrans(&na,10);
    nc.addTrans(&nb,20);
    nc.addTrans(&ne,20);

    //Node D
    nd.addTrans(&na,5);
    nd.addTrans(&ne,20);

    //Node E
    ne.addTrans(&nb,100);
    ne.addTrans(&nc,20);
    ne.addTrans(&nd,20);

    g.nodes.push_back(na);
    g.nodes.push_back(nb);
    g.nodes.push_back(nc);
    g.nodes.push_back(nd);
    g.nodes.push_back(ne);

    g.genDotOutput();

}