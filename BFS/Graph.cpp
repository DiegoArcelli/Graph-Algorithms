#include "Graph.h"
#include <cstdlib>
#include <iostream>
#include <vector>

Graph::Graph(int n){
    this->n = n;
    this->adj = new vector<Node>;
    this->Q = new queue<Node>;
    this->BF = new vector<Edge>;
}

Graph::~Graph() {
}

void Graph::createRandomGraph(){
    int r;
    srand (time(NULL));
    vector<Node>::iterator itr;
    for (int i = 0; i < n; i++){
        Node node(i);
        node.setStatus(WHITE);
        adj->push_back(node);
    }
    for (itr = adj->begin(); itr != adj->end(); itr++){
        for (int j = 0; j < n; j ++) {
            r = rand() % 2;
            if(r == 0 && j != itr->getValue()){
                itr->addNode(&adj->at(j));
            }
        }
    }
}

void Graph::printGraph(){
    vector<Node>::iterator itr;
    vector<Node*>::iterator list_itr;
    for (itr = adj->begin(); itr != adj->end(); itr++) {
        cout << "|" << itr->getValue() << "| -> ";
        for (list_itr = itr->linked->begin(); list_itr != itr->linked->end(); list_itr++){
            cout << "|" << (*list_itr)->getValue() << "| -> ";
        }
        cout << endl;
    }
}

void Graph::printBF(){
    vector<Edge>::iterator itr;
    cout << "{";
    for (itr = BF->begin(); itr != BF->end(); itr++){
        itr->printEdge();
    }
    cout  << "}" << endl;
}

void Graph::BFS(int s){
    vector<Node>::iterator itr;
    for (itr = adj->begin(); itr != adj->end(); itr++) {
        if (itr->getValue() != s) {
            itr->setStatus(WHITE);
            itr->setDistance(INT32_MAX);
        }
    }
    adj->at(s).setDistance(0);
    Q->push(adj->at(s));
    while (!Q->empty()) {
        Node u = Q->front();
        Q->pop();
        vector<Node*>::iterator itr;
        for (itr = u.linked->begin(); itr != u.linked->end(); itr++) {
            if ((*itr)->getStatus() == WHITE) {
                (*itr)->setStatus(GREY);
                (*itr)->setDistance(adj->at(u.getValue()).getDistance() + 1);
                Q->push(adj->at((*itr)->getValue()));
                BF->push_back(Edge(u.getValue(),(*itr)->getValue()));
            }
        }
        adj->at(u.getValue()).setStatus(BLACK);
        cout << "Visit of " << u.getValue() << " ended" << endl;
    }
    
}