#include <iostream>
#include "Node.h"
#include "Graph.h"

using namespace std;

int main(int argc, char const *argv[]){

    Graph g(5);
    g.createRandomGraph();
    cout << "Graph:" << endl;
    g.printGraph();
    g.BFS(0);
    cout << endl << "BF tree:" << endl;
    g.printBF();
    
}
