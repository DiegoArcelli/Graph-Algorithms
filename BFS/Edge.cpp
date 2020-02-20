#include "Edge.h"
#include <iostream>

using namespace std;

Edge::Edge(int from, int to) {
    this->from = from;
    this->to = to;
}

Edge::~Edge() {
    
}

void Edge::printEdge() {
    cout << "(" << from << ", " << to << ")";
}
