#include "Graph.h"
#include <cstdlib>
#include <iostream>
#include <vector>

Graph::Graph(int n){
    this->n = n;
    this->adj = new vector<Node>;
    this->T = new vector<Edge>;
    this->B = new vector<Edge>;
    this->F = new vector<Edge>;
    this->C = new vector<Edge>;
    
}

Graph::~Graph() {
}

void Graph::setTime(int new_time){
    this->dfs_time = new_time;
}

int Graph::getTime(){
    return this->dfs_time;
}

void Graph::increaseTime(){
    this->dfs_time++;
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


void Graph::printTree(){
    vector<Edge>::iterator itr;
    cout << "{";
    for (itr = T->begin(); itr != T->end(); itr++){
        itr->printEdge();
    }
    cout  << "}" << endl;
}

void Graph::printBackward(){
    vector<Edge>::iterator itr;
    cout << "{";
    for (itr = B->begin(); itr != B->end(); itr++){
        itr->printEdge();
    }
    cout  << "}" << endl;
}

void Graph::printForward(){
    vector<Edge>::iterator itr;
    cout << "{";
    for (itr = F->begin(); itr != F->end(); itr++){
        itr->printEdge();
    }
    cout  << "}" << endl;
}

void Graph::printCross(){
    vector<Edge>::iterator itr;
    cout << "{";
    for (itr = C->begin(); itr != C->end(); itr++){
        itr->printEdge();
    }
    cout  << "}" << endl;
}

void Graph::DFS(){
    this->dfs_time = 0;
    vector<Node>::iterator itr;
    for (itr = adj->begin(); itr != adj->end(); itr++) {
        itr->setStatus(WHITE);
        itr->setStartingTime(0);
        itr->setEndingTime(0);
    }
    for (itr = adj->begin(); itr != adj->end(); itr++) {
        if(adj->at(itr->getValue()).getStatus() == WHITE){
            DFSVisit(itr->getValue());
        }
    }
}

void Graph::DFSVisit(int v){
    dfs_time++;
    cout << "|" << adj->at(v).getValue() << "| -> ";
    adj->at(v).setStatus(GREY);
    adj->at(v).setStartingTime(dfs_time);
    vector<Node*>::iterator itr;
    for (itr = adj->at(v).linked->begin(); itr != adj->at(v).linked->end(); itr++) {
        if((*itr)->getStatus() == WHITE){
            T->push_back(Edge(v,(*itr)->getValue()));
            DFSVisit((*itr)->getValue());
        } else if((*itr)->getStatus() == GREY){
            B->push_back(Edge(v,(*itr)->getValue()));
        } else {
            if(adj->at(v).getStartingTime() < (*itr)->getStartingTime()) {
                F->push_back(Edge(v,(*itr)->getValue()));
            } else {
                C->push_back(Edge(v,(*itr)->getValue()));
            }
        }
    }
    dfs_time++;
    adj->at(v).setStatus(BLACK);
    adj->at(v).setEndingTime(dfs_time);
}