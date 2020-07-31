#include "Heap.h"
#include <iostream>

Heap::Heap(int n, vector<Node>* array) {
    this->n = n;
    H = new Node*[n];
    vector<Node>::iterator itr;
    int i = 0;
    for (int i = 0; i < n; i++) {
        H[i] = &array->at(i);
        H[i]->setHeapPos(i);
    }
}

Heap::~Heap() {

}

void Heap::heapify(int i) {
    if (n - 1 >= 2*i + 2) {
        int w;
        if (H[2*i + 2]->getDistance() <= H[2*i + 1]->getDistance()) {
            w = 2*i + 2;
        } else {
            w = 2*i + 1;
        }
        if (H[i]->getDistance() >= H[w]->getDistance()){
            H[i]->setHeapPos(w);
            H[w]->setHeapPos(i);
            Node* tmp = H[i];
            H[i] = H[w];
            H[w] = tmp;
            heapify(w);
        }
    } else if (n - 1 == 2*i + 1) {
        if (H[2*i + 1]->getDistance() <= H[i]->getDistance()) {
            H[i]->setHeapPos(2*i + 1);
            H[2*i + 1]->setHeapPos(i);
            Node* tmp = H[i];
            H[i] = H[2*i + 1];
            H[2*i + 1] = tmp;
        }
    }
}

void Heap::buildMaxHeap() {
    for (int i = (n-1)/2; i >=0; i--) {
        heapify(i);
    }
}

void Heap::printHeap(){
    for (int i = 0; i < n; i++)
        cout << "(" << H[i]->getValue() << "," << H[i]->getDistance() <<  ") - ";
    cout << endl;
}

Node* Heap::extractMin() {
    if (n > 0) {
        H[n-1]->setHeapPos(0);
        H[0]->setHeapPos(n-1);
        Node* tmp = H[n-1];
        H[n-1] = H[0];
        H[0] = tmp;
        n--;
        heapify(0);
        return H[n];
    } else {
        return NULL;
    }
}

void Heap::restoreHeap(int i) {
    while (H[i]->getDistance() <= H[(i-1)/2]->getDistance() && i > 0) {
        H[i]->setHeapPos((i-1)/2);
        H[(i-1)/2]->setHeapPos(i);
        Node *tmp = H[i];
        H[i] = H[(i-1)/2];
        H[(i-1)/2] = tmp;
        i = (i-1)/2;
    }
}

bool Heap::isEmpty() {
    return n > 0 ? false : true;
}