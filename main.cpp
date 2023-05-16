#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int label;
    vector<int> neighbours;
};

struct Graph {
    int n;
    Node* nodes;

    Graph(int numNodes) {
        n = numNodes;
        nodes = new Node[n];
    }

    void initializeNodes() {
        for (int i = 0; i < n; i++) {
            nodes[i].label = i + 1;
        }
    }

    void addEdge(int u, int v) {
        nodes[u - 1].neighbours.push_back(v);
        nodes[v - 1].neighbours.push_back(u);
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << "Node " << nodes[i].label << " neighbours: ";
            for (int neighbour : nodes[i].neighbours) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numNodes = 8;
    Graph* g = new Graph(numNodes);
    g->initializeNodes();
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(1, 5);
    g->addEdge(2, 3);
    g->addEdge(2, 6);
    g->addEdge(4, 6);
    g->addEdge(4, 8);
    g->addEdge(5, 8);
    g->addEdge(5, 7);
    g->addEdge(4, 7);
    g->print();

    delete g;
    return 0;
}
