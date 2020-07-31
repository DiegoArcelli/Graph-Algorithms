#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <queue>
#include "Node.h"
#include "Heap.h"

using namespace std;

class Graph {
private:
    int n;
    vector<Node> *adj;
    int **weights;
    Heap *Q;
public:
    Graph(int n);
    ~Graph();
    void createRandomGraph();
    void randomNegativeWeightedEdges();
    void printGraph();
    void dijkstraRelax(int u, int v);
    void Dijkstra(int s);
    void printShortestPaths(int s);
    void bellmanFordRelax(int u, int v);
    bool BellmanFord(int s);
};

#endif