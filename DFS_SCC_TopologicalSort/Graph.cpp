#include "Graph.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

Graph::Graph(int n){
    this->n = n;
    this->adj = new vector<Node>;
    this->T = new vector<Edge>;
    this->B = new vector<Edge>;
    this->F = new vector<Edge>;
    this->C = new vector<Edge>;
    this->ordered = new vector<Node>;
    this->sort = new list<Node>;
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
    for (int i = 0; i < this->n; i++){
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

void Graph::createEmptyGraph() {
    vector<Node>::iterator itr;
    for (int i = 0; i < this->n; i++){
        Node node(i);
        node.setStatus(WHITE);
        adj->push_back(node);
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
    reverse(ordered->begin(),ordered->end());
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
    ordered->push_back(adj->at(v));
    dfs_time++;
    adj->at(v).setStatus(BLACK);
    adj->at(v).setEndingTime(dfs_time);
}


void Graph::setOrdered(vector<Node>* list) {
    ordered = list;
}


void Graph::addEdge(int from, int to){
    if (from < this->n && to < this-> n) {
        this->adj->at(from).addNode(&adj->at(to));
    }
}


Graph Graph::createTransposeGraph() {
    Graph transpose(this->n);
    transpose.createEmptyGraph();
    transpose.setOrdered(ordered);
    vector<Node>::iterator itr;
    vector<Node*>::iterator list_itr;
    for (itr = adj->begin(); itr != adj->end(); itr++) {
        for (list_itr = itr->linked->begin(); list_itr != itr->linked->end(); list_itr++){
            transpose.addEdge((*list_itr)->getValue(), itr->getValue());
        }
    }
    return transpose;
}



void Graph::SCC_DFS() {
    vector<Node>::iterator itr;
    int i = 0;
    for (itr = ordered->begin(); itr != ordered->end(); itr++) {
        itr->setStatus(WHITE);
    }
    for (itr = ordered->begin(); itr != ordered->end(); itr++) {
        if (ordered->at(itr->getValue()).getStatus() == WHITE){
            scc.push_back({});
            SCC_DFSVisit(itr->getValue(), i);
            i++;
        }
    }
}


void Graph::SCC_DFSVisit(int v, int set) {
    adj->at(v).setStatus(GREY);
    vector<Node*>::iterator itr;
    scc.at(set).push_back(v);
    for (itr = adj->at(v).linked->begin(); itr != adj->at(v).linked->end(); itr++) {
        if ((*itr)->getStatus() == WHITE) {
            SCC_DFSVisit((*itr)->getValue(), set);
        }
    }
    ordered->at(v).setStatus(BLACK);
}


void Graph::printSCC() {
    vector<vector<int>>::iterator itr;
    vector<int>::iterator inner_itr;
    int i = 0;
    for (itr = scc.begin(); itr != scc.end(); ++itr) {
        cout << "Strongly connected component " << i++ << ": ";
        for (inner_itr = itr->begin(); inner_itr != itr->end(); ++inner_itr) {
            cout << *inner_itr << " ";
        }
        cout << endl;
    }
}


void Graph::clear_lists() {
    free(B);
    free(T);
    free(C);
    free(F);
    this->T = new vector<Edge>;
    this->B = new vector<Edge>;
    this->F = new vector<Edge>;
    this->C = new vector<Edge>;
}


void Graph::remove_edge(int from, int to) {
    adj->at(from).removeNode(to);
}


Graph Graph::createDAG() {
    Graph dag = *this;
    if (!B->empty()){
        vector<Edge>::iterator itr;
        for (itr = B->begin(); itr != B->end(); ++itr) {
            dag.remove_edge(itr->getFrom(), itr->getTo());
        }
    }
    dag.clear_lists();
    return dag;
}


void Graph::topologicalSort(){
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


void Graph::TSort_DFSVisit(int v){
    vector<Node*>::iterator itr;
    adj->at(v).setStatus(GREY);
    for (itr = adj->at(v).linked->begin(); itr != adj->at(v).linked->end(); itr++) {
        if((*itr)->getStatus() == WHITE){
            DFSVisit((*itr)->getValue());
        }
    }
    sort->push_front(adj->at(v));
    adj->at(v).setStatus(BLACK);
}

void Graph::printSortedDAG(){
    list<Node>::iterator itr;
    for (itr = sort->begin(); itr != sort->end(); itr++) {
        cout << "|" << itr->getValue() << "| -> ";
    }
    cout << endl;
}