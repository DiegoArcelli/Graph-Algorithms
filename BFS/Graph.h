#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <queue>
#include "Node.h"
#include "Edge.h"

using namespace std;

class Graph {
private:
    int n; //number of nodes
    vector<Node> *adj; //adjacency list
    vector<Edge> *BF;
    queue<Node> *Q;
public:
    Graph(int n);
    ~Graph();
    void createRandomGraph();
    void printGraph();
    void printBF();
    void BFS(int s);
};

#endif