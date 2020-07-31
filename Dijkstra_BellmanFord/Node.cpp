#include "Node.h"
#include <list>
#include <iostream>

using namespace std;

Node::Node(int value) {
    this->value = value;
    heap_pos = -1; 
    this->parent = (Node*)NULL;
    linked = new vector<Node*>;
}

Node::Node() {
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

void Node::setDistance(int distance) {
    this->distance = distance;
}

int Node::getDistance() {
    return this->distance;
}

void Node::setParent(Node* newParent) {
    this->parent = newParent;
}

void Node::setHeapPos(int heap_pos) {
    this->heap_pos = heap_pos;
}

int Node::getHeapPos() {
    return this->heap_pos;
}

Node* Node::getParent() {
    return this->parent;
}