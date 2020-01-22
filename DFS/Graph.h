#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "Node.h"

using namespace std;

class Graph {
private:
    int n; //number of nodes
    vector<Node> *adj; //adjacency list
public:
    Graph(int n);
    ~Graph();
    void createRandomGraph();
    void addEdge(int v, int w);
    void printGraph();
    void DFS();
    void DFSVisit(int v);
};

#endif