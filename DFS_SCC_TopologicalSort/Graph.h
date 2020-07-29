#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>
#include "Node.h"
#include "Edge.h"

using namespace std;

class Graph {
private:
    int n; 
    int dfs_time;
    vector<Node> *adj;
    vector<Edge> *T;
    vector<Edge> *B;
    vector<Edge> *F;
    vector<Edge> *C;
    vector<Node> *ordered;
    vector<vector<int>> scc;
    list<Node> *sort;
public:
    Graph(int n);
    ~Graph();
    void createRandomGraph();
    void createEmptyGraph();
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
    void setOrdered(vector<Node>* list);
    void addEdge(int from, int to);
    Graph createTransposeGraph();
    void SCC_DFS();
    void SCC_DFSVisit(int v, int set);
    void printSCC();
    void clear_lists();
    void remove_edge(int from, int to);
    Graph createDAG();
    void topologicalSort();
    void TSort_DFSVisit(int v);
    void printSortedDAG();
};

#endif