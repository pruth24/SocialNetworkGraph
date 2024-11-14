// include/Graph.h

#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <list>
#include <vector>
#include <string>
#include <limits>

struct Node {
    int id;
    std::string name;
    Node() : id(-1), name("") {}
    Node(int id, const std::string &name) : id(id), name(name) {}
};

struct Edge {
    int source;
    int target;
    double weight;
    Edge(int source, int target, double weight) : source(source), target(target), weight(weight) {/*std::cout<<"Edge is initialzed";*/}
};

class Graph {
public:
    Graph();
    void addNode(int id, const std::string &name);
    void addEdge(int source, int target, double weight = 1.0);

    void BFS(int startNode);
    void DFS(int startNode);

    std::vector<double> dijkstra(int startNode);
    std::vector<double> pageRank(int iterations, double damping = 0.85);

    void calculateCentrality();

    std::unordered_map<int, Node> nodes;
    std::unordered_map<int, std::list<Edge> > adjList;
};

#endif
