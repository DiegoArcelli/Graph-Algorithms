#ifndef HEAP_H
#define HEAP_H
#include "Node.h"
#include <vector>

using namespace std;

class Heap {
private:
    int n;
    Node** H;
public:
    Heap(int n, vector<Node>* array);
    ~Heap();
    void buildMaxHeap();
    void heapify(int i);
    void printHeap();
    Node* extractMin();
    void restoreHeap(int i);
    bool isEmpty();
};

#endif
