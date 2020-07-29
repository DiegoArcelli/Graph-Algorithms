#ifndef EDGE_H
#define EDGE_H

using namespace std;

class Edge {
private:
    int from;
    int to;
public:
    Edge(int from, int to);
    ~Edge();
    void printEdge();
    int getFrom();
    int getTo();
};


#endif