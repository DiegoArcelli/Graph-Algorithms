#include "Graph.h"
#include <cstdlib>
#include <iostream>
#include <vector>

Graph::Graph(int n){
    this->n = n;
    this->adj = new vector<Node>;
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

void Graph::DFS(){
    vector<Node>::iterator itr;
    for (itr = adj->begin(); itr != adj->end(); itr++) {
        itr->setStatus(WHITE);
    }
    for (itr = adj->begin(); itr != adj->end(); itr++) {
        if(adj->at(itr->getValue()).getStatus() == WHITE){
            DFSVisit(itr->getValue());
        }
    }
}

void Graph::DFSVisit(int v){
    cout << "Visited: " << v << endl;
    adj->at(v).setStatus(GREY);
    vector<Node*>::iterator itr;
    for (itr = adj->at(v).linked->begin(); itr != adj->at(v).linked->end(); itr++) {
        if((*itr)->getStatus() == WHITE){
            DFSVisit((*itr)->getValue());
        }
    }
    adj->at(v).setStatus(BLACK);
}