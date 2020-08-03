#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char const *argv[]){

    Graph g(5);
    cout << "Non negative weighted graph:" << endl;
    g.createRandomGraph();
    g.printGraph();
    cout << endl;
    cout << "Dijkstra execution: " << endl << endl;
    g.Dijkstra(0);
    g.printShortestPaths(0);
    g.randomNegativeWeightedEdges();
    cout << "Weighted graph:" << endl;
    g.printGraph();
    cout << endl;
    cout << "Bellman-Ford execution:" << endl << endl;
    if (g.BellmanFord(0))
        g.printShortestPaths(0);
    else
        cout << "Detected negative weighted cycle" << endl;
    
}
