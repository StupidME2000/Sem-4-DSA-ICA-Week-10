#include <iostream>
#include <list>
using namespace std;

// Structure representing a node in the graph
struct Node {
    int label;                // Node label
    list<int> neighbours;     // List of neighbouring nodes
};

// Graph data structure
struct Graph {
    int n = 8;                // Total number of nodes in the graph
    Node* nodes = new Node[n];  // Array of nodes

    // Initialize the nodes with labels
    void initializeNodes() {
        for (int i = 0; i < n; i++) {
            nodes[i].label = i + 1;
        }
    }

    // Add an undirected edge between two nodes
    void addEdge(int u, int v) {
        // Check if the edge (u, v) or (v, u) is already present
        for (int neighbour : nodes[u - 1].neighbours) {
            if (neighbour == v) {
                return;  // Edge already exists
            }
        }
        // If the edge is not already present, add it
        nodes[u - 1].neighbours.push_back(v);
        nodes[v - 1].neighbours.push_back(u);
    }

    // Print the adjacency list of the graph
    void print() {
        for (int i = 0; i < n; i++) {
            cout << "Node " << nodes[i].label << " neighbours: ";
            for (int neighbour : nodes[i].neighbours) {
                cout << "--> " << neighbour;
            }
            cout << endl;
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->initializeNodes();

    // Add edges for the graph (undirected)
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(1, 5);
    g->addEdge(2, 3);
    g->addEdge(2, 6);
    g->addEdge(4, 6);
    g->addEdge(4, 7);
    g->addEdge(4, 8);
    g->addEdge(5, 6);
    g->addEdge(5, 7);
    g->addEdge(5, 8);

    // Print the graph adjacency list
    g->print();

    delete g;
    return 0;
}
