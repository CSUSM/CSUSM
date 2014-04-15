#include <fstream>
#include <iostream>
#include <string>
#include "slist.hh"
 
#define SIZE 20
 
// An entry in dgraph.Gtable
struct Gvertex {
    // The out degree
    int degree;
    // The mark/visit number
    int visit;
    // A linked link struct for adjacent vertices
    slist adjacents;
    // a vertex name
    char name;
};
 

class dgraph {
private:
    Gvertex Gtable[SIZE];
    // How many slots are used.
    int     used;
 
public:
    // PURPOSE : Initialize the table entries.
    dgraph(void)
    {
        this->used = 0;
        for (int i = 0; i < SIZE; ++i) {            
            this->Gtable[i].name = ' ';
            this->Gtable[i].degree = 0;
            this->Gtable[i].visit = 0;
        }
    }

    // Destructor is useless
 
    // PURPOSE : Reads the input file table.txt to fill the table
    void fillTable(void)
    {
        std::ifstream   fin("table.txt", std::ios::in);
        char            x;
 
        while (fin >> x) {
            Gtable[used].name = x;
            fin >> (Gtable[used].degree);
            for (int i = 0; i < Gtable[used].degree; ++i) {
                fin >> x;
                Gtable[used].adjacents.addFront(x);
            }
            ++used;
        }
    }
 
    // PURPOSE : Displays the table content in a very readable format.
    void displayGraph(void)
    {
        char tmp;
        for (int i = 0; i < this->used; ++i) {
            std::cout << Gtable[i].name << ":" << std::endl;
            if (!Gtable[i].adjacents.isEmpty())
                Gtable[i].adjacents.displayAll();
            else
                std::cout << "[Empty]" << std::endl;
        }
    }
 
    // PURPOSE : Returns the out degree of the vertex whose name is given
    //              as an argument, or -1 on failure.
    int findOutDegree(char c)
    {
        for (int i = 0; i < this->used; ++i)
            if (Gtable[i].name == c)
                return Gtable[i].degree;
        return -1;
    }
 
    // PURPOSE : Returns the linked list of adjacent vertices of the
    //              vertex whose name is given as an argument.
    slist findAdjacency(char c)
    {
        for (int i = 0; i < this->used; ++i)
            if (Gtable[i].name == c)
                return Gtable[i].adjacents;
        return slist();    
    }
};
