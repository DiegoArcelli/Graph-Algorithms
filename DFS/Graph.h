#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "Node.h"
#include "Edge.h"

using namespace std;

class Graph {
private:
    int n; //number of nodes
    int dfs_time;
    vector<Node> *adj; //adjacency list
    vector<Edge> *T; //list of all tree edges
    vector<Edge> *B; //list of all backward edges
    vector<Edge> *F; //list of all forward edges
    vector<Edge> *C; //list of all cross edges
public:
    Graph(int n);
    ~Graph();
    void createRandomGraph();
    void printGraph();
    void DFS();
    void DFSVisit(int v);
    void setTime(int new_time);
    int getTime();
    void increaseTime();
    void printTree();
    void printBackward();
    void printForward();
    void printCross();
};

#endif