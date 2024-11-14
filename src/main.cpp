// src/main.cpp

#include "Graph.h"
#include "Visualization.h"
#include <iostream>

int main() {
    Graph graph;

    // Add nodes
    graph.addNode(0, "Alice");
    graph.addNode(1, "Bob");
    graph.addNode(2, "Carol");
    graph.addNode(3, "Dave");

    // Add edges
    graph.addEdge(0, 1, 1.0);
    graph.addEdge(1, 3, 2.0);
    graph.addEdge(2, 3, 1.0);
    graph.addEdge(3, 0, 1.0);
    graph.addEdge(2, 0, 2.0);


    // Perform BFS and DFS
    std::cout << "BFS Traversal starting from node 0:\n";
    graph.BFS(0);
    std::cout << "\nDFS Traversal starting from node 0:\n";
    graph.DFS(0);

    // Dijkstra
    std::vector<double> distances = graph.dijkstra(0);
    std::cout << "\nShortest distances from node 0:\n";
    for (int i = 0; i < distances.size(); ++i) {
        std::cout << "Distance to node " << i << ": " << distances[i] << "\n";
    }

    // Generate visualization
    Visualization::generateDotFile(graph, "graph.dot");

    return 0;
}
