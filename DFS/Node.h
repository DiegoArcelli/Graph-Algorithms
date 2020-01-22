#ifndef NODE_H
#define NODE_H
#include <vector>
#include <string>

using namespace std;

enum status {
    WHITE,
    GREY,
    BLACK    
};

class Node {
private:
    int value;
    status color;
public:
    vector<Node*> *linked;
    Node(int value);
    ~Node();
    int getValue();
    status getStatus();
    void addNode(Node* node);
    void setStatus(status s);
};

#endif
