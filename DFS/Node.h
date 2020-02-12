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
    int start;
    int end;
public:
    vector<Node*> *linked;
    Node(int value);
    ~Node();
    int getValue();
    status getStatus();
    void addNode(Node* node);
    void setStatus(status s);
    void setStartingTime(int time);
    void setEndingTime(int time);
    int getStartingTime();
    int getEndingTime();
};

#endif
