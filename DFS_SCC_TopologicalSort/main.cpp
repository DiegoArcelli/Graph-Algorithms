#include <iostream>
#include "Node.h"
#include "Graph.h"

using namespace std;

int main(int argc, char const *argv[]){

    Graph g(5);
    g.createRandomGraph();
    cout << "Graph:" << endl;
    g.printGraph();
    cout << endl << "Executing DFS:" << endl;
    g.DFS();
    cout << endl << endl;
    cout << "Tree edges:" << endl; 
    g.printTree();
    cout << endl;
    cout << "Backward edges:" << endl;
    g.printBackward();
    cout << endl;
    cout << "Forward edges:" << endl; 
    g.printForward();
    cout << endl;
    cout << "Cross edges:" << endl; 
    g.printCross();
    cout << endl;
    cout << "Transpose graph:" << endl;
    Graph t = g.createTransposeGraph();
    t.printGraph();
    cout << endl;
    t.SCC_DFS();
    t.printSCC();
    cout << endl;
    cout << "DAG:" << endl;
    Graph DAG = g.createDAG();
    DAG.printGraph();
    cout << endl;
    cout << "Toloplogical sort:" << endl;
    DAG.topologicalSort();
    DAG.printSortedDAG();
    return 0;

}
