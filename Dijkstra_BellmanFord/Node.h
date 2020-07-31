#ifndef NODE_H
#define NODE_H
#include <vector>
#include <string>

using namespace std;

class Node {
private:
    int value;
    int distance;
    int heap_pos;
    Node* parent;
public:
    vector<Node*> *linked;
    Node(int value);
    Node();
    ~Node();
    int getValue();
    void addNode(Node* node);
    void setDistance(int distance);
    int getDistance();
    void setParent(Node* newParent);
    void setHeapPos(int heap_post);
    int getHeapPos();
    Node* getParent();
};

#endif
