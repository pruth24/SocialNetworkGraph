// src/Visualization.cpp

#include "Visualization.h"
#include <fstream>

void Visualization::generateDotFile(const Graph &graph, const std::string &filename) {
    std::ofstream file(filename);
    file << "digraph G {\n";

    for (const auto &[id, node] : graph.nodes) {
        file << "    " << id << " [label=\"" << node.name << "\"];\n";
    }

    for (const auto &[source, edges] : graph.adjList) {
        for (const auto &edge : edges) {
            file << "    " << edge.source << " -> " << edge.target;
            if (edge.weight != 1.0) file << " [label=\"" << edge.weight << "\"]";
            file << ";\n";
        }
    }

    file << "}\n";
    file.close();
}
