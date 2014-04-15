#include <iostream>
#include "dgraph.hh"
  
int main(void)
{
    dgraph  graph;
    char    c = ' ';
 
    graph.fillTable();
    graph.displayGraph();

    int degreeFound = -1;
    while (true) {
        std::cout << "Enter a vertex name to get the out degree ('!' to exit): "
                  << std::endl;
        std::cin >> c;
        if (c == '!')
            break;
        if ((degreeFound = graph.findOutDegree(c)) == -1)
            std::cout << "Wrong name provided, result was not found." << std::endl;
        else
            std::cout << "Value found: " <<  degreeFound << std::endl;
    }

    slist   listFound;
    while (true) {
        std::cout
            << "Enter a vertex name to get the adjacent vertices ('!' to exit):"
            << std::endl;
        std::cin >> c;
        if (c == '!')
            break;
        listFound = graph.findAdjacency(c);
        if (listFound.isEmpty())
            std::cout << "[Empty result]" << std::endl;
        else
            listFound.displayAll();
    }
    return 0;
}
