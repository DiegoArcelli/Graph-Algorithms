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