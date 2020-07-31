#include "Graph.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

Graph::Graph(int n){
    this->n = n;
    this->adj = new vector<Node>;
    this->weights = new int*[n];
    for (int i = 0; i < n; i++) {
        weights[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i!=j)
                weights[i][j] = INT32_MAX;
            else
                weights[i][j] = 0;
        }
    }
}

Graph::~Graph() {
}

void Graph::createRandomGraph() {
    int r;
    srand (time(NULL));
    vector<Node>::iterator itr;
    for (int i = 0; i < n; i++){
        Node node(i);
        adj->push_back(node);
    }
    for (itr = adj->begin(); itr != adj->end(); itr++){
        for (int j = 0; j < n; j ++) {
            r = rand() % 2;
            if(r == 0 && j != itr->getValue()){
                itr->addNode(&adj->at(j));
                int weight = rand() % 10;
                weights[itr->getValue()][j] = weight;
            }
        }
    }
}

void Graph::randomNegativeWeightedEdges() {
    int r;
    srand (time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (weights[i][j] != INT32_MAX && i != j) {
                r = rand() % 19 - 9;
                weights[i][j] = r;
            }
        }
    }
}

void Graph::printGraph() {
    vector<Node>::iterator itr;
    vector<Node*>::iterator list_itr;
    for (itr = adj->begin(); itr != adj->end(); itr++) {
        cout << "|" << itr->getValue() << "| ";
        for (list_itr = itr->linked->begin(); list_itr != itr->linked->end(); list_itr++){
            cout << "-(";
            if (weights[itr->getValue()][(*list_itr)->getValue()] >= 0) 
                cout << "+" << weights[itr->getValue()][(*list_itr)->getValue()];
            else
                cout << "-" << -weights[itr->getValue()][(*list_itr)->getValue()];
            cout << ")-> |" << (*list_itr)->getValue() << "| ";
        }
        cout << endl;
    }
}

void Graph::dijkstraRelax(int u, int v) {
    if (adj->at(u).getDistance() + weights[u][v] < adj->at(v).getDistance() && adj->at(u).getDistance() != INT32_MAX) {
        adj->at(v).setDistance(adj->at(u).getDistance() + weights[u][v]);
        adj->at(v).setParent(&adj->at(u));
        Q->restoreHeap(adj->at(v).getHeapPos());
    }
}

void Graph::Dijkstra(int s) {
    vector<Node>::iterator itr;
    for (itr = adj->begin(); itr != adj->end(); ++itr) {
        itr->setDistance(INT32_MAX);
        itr->setParent(NULL);
    }
    adj->at(s).setDistance(0);
    Q = new Heap(adj->size(), adj);
    while (!Q->isEmpty()) {
        Node* u = Q->extractMin();
        vector<Node*>::iterator itr;
        for (itr = adj->at(u->getValue()).linked->begin(); itr != adj->at(u->getValue()).linked->end(); itr++) {
            this->dijkstraRelax(u->getValue(), (*itr)->getValue());
        }
    }
    
}


void Graph::bellmanFordRelax(int u, int v) {
    if (adj->at(u).getDistance() + weights[u][v] < adj->at(v).getDistance() && adj->at(u).getDistance() != INT32_MAX) {
        adj->at(v).setDistance(adj->at(u).getDistance() + weights[u][v]);
        adj->at(v).setParent(&adj->at(u));
    }
}

bool Graph::BellmanFord(int s) {
    vector<Node>::iterator itr;
    vector<Node*>::iterator inner_itr;
    for (itr = adj->begin(); itr != adj->end(); ++itr) {
        itr->setDistance(INT32_MAX);
        itr->setParent(NULL);
    }
    adj->at(s).setDistance(0);
    for (int i = 0; i < n -1; i++) {
        for (itr = adj->begin(); itr != adj->end(); itr++) {
            for (inner_itr = itr->linked->begin(); inner_itr != itr->linked->end(); inner_itr++) {
                this->bellmanFordRelax(itr->getValue(),(*inner_itr)->getValue());
            }
        }
    }
    for (itr = adj->begin(); itr != adj->end(); itr++) {
        for (inner_itr = itr->linked->begin(); inner_itr != itr->linked->end(); inner_itr++) {
            if (adj->at(itr->getValue()).getDistance() + weights[itr->getValue()][(*inner_itr)->getValue()] < adj->at((*inner_itr)->getValue()).getDistance() && adj->at(itr->getValue()).getDistance() != INT32_MAX) {
                return false;    
            }
        }
    }
    return true;
}

void Graph::printShortestPaths(int s) {
    for (int i = 0; i < n; i++) {
        Node scan = adj->at(i);
        cout << "Shortest path form " << s << " to " << i << ":" << endl;
        if (scan.getParent() != NULL || i == s) {
            vector<int> path;
            vector<int>::iterator itr;
            while (scan.getParent() != NULL) {
                path.push_back(scan.getValue());
                scan = adj->at(scan.getParent()->getValue());
            }
            reverse(path.begin(),path.end());
            int path_weight = 0;
            int parent = s;
            cout << s;
            for (itr = path.begin(); itr != path.end(); itr++) {
                cout << " -(" << weights[parent][*itr] << ")-> " << *itr;
                path_weight += weights[parent][*itr];
                parent = *itr;
            }
            cout << endl << "Path weight: " << path_weight << endl << endl;
        } else {
            cout << "No path" << endl << endl;
        }

    }
}