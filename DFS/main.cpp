#include <iostream>
#include "Node.h"
#include "Graph.h"

using namespace std;

int main(int argc, char const *argv[]){

    Graph g(4);
    g.createRandomGraph();
    g.printGraph();
    g.DFS();
    return 0;

}
