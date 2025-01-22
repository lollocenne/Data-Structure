#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class Graph {
private:
    unordered_map<int, list<int>> adjacencyList;

public:
    // Add an edge to the graph
    // Time complexity O(1)
    void addEdge(int source, int destination, bool isDirected = true) {
        adjacencyList[source].push_back(destination);
        if (!isDirected) {
            adjacencyList[destination].push_back(source);
        }
    }
    
    // Display the graph
    // Time complexity O(n + e) where n is the number of nodes and e is the number of edges
    void printGraph() const {
        for (const auto& pair : adjacencyList) {
            cout<<pair.first<<": ";
            for (const auto& neighbor : pair.second) {
                cout<<neighbor<<", ";
            }
            cout<<endl;
        }
    }
    
    // Check if a node exists in the graph
    // Time complexity O(1)
    bool hasNode(int node) const {
        return adjacencyList.find(node) != adjacencyList.end();
    }
    
    // Get neighbors of a node
    // Time complexity O(d) where d is the number of neighbors
    vector<int> getNeighbors(int node) const {
        vector<int> neighbors;
        if (adjacencyList.find(node) != adjacencyList.end()) {
            for (const auto& neighbor : adjacencyList.at(node)) {
                neighbors.push_back(neighbor);
            }
        }
        return neighbors;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.printGraph();
    
    int node = 2;
    cout<< "Neighbors of node "<<node<< ": ";
    vector<int> neighbors = g.getNeighbors(node);
    for (int neighbor : neighbors) {
        cout<<neighbor<<", ";
    }
    cout<<endl;
    
    return 0;
}