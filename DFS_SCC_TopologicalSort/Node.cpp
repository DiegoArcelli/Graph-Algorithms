#include "Node.h"
#include <list>
#include <iostream>

Node::Node(int value) {
    this->value = value;
    linked = new vector<Node*>;
}

Node::~Node() {
}

int Node::getValue(){
    return value;
}

void Node::addNode(Node* node) {
    linked->push_back(node);    
}

void Node::setStatus(status s){
    color = s;
}

status Node::getStatus(){
    return color;
}

void Node::setStartingTime(int time) {
    this->start = time;
}

void Node::setEndingTime(int time) {
    this->end = time;
}

int Node::getStartingTime() {
    return this->start;
}

int Node::getEndingTime() {
    return this->end;
}


void Node::removeNode(int v) {
    vector<Node*>::iterator itr;
    vector<int> toDelete;
    int i = 0;
    for (itr = linked->begin(); itr != linked->end(); ++itr) {
        if ((*itr)->getValue() == v) {
            toDelete.push_back(i);
        }
        i++;
    }
    vector<int>::iterator int_itr;
    for (int_itr = toDelete.begin(); int_itr != toDelete.end(); ++int_itr) {
        linked->erase(linked->begin() + *int_itr);
    }
}