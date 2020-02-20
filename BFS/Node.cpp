#include "Node.h"
#include <list>
#include <iostream>

using namespace std;

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

void Node::setStatus(status s) {
    color = s;
}

status Node::getStatus() {
    return color;
}

void Node::setDistance(int distance) {
    this->distance = distance;
}

int Node::getDistance() {
    return this->distance;
}