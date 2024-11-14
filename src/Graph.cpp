// src/Graph.cpp

#include "Graph.h"
#include <queue>
#include <iostream>
#include <stack>
#include <numeric>

Graph::Graph() {}

void Graph::addNode(int id, const std::string &name) {
    nodes[id] = Node(id, name);
}

void Graph::addEdge(int source, int target, double weight) {
    adjList[source].push_back(Edge(source, target, weight));
    //adjList[source].push_back({source, target, weight});
}

void Graph::BFS(int startNode) {
    std::queue<int> q;
    std::unordered_map<int, bool> visited;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << "Visited " << nodes[node].name << "\n";

        for (const auto &edge : adjList[node]) {
            if (!visited[edge.target]) {
                visited[edge.target] = true;
                q.push(edge.target);
            }
        }
    }
}

void Graph::DFS(int startNode) {
    std::stack<int> s;
    std::unordered_map<int, bool> visited;
    s.push(startNode);

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        if (!visited[node]) {
            visited[node] = true;
            std::cout << "Visited " << nodes[node].name << "\n";
        }

        for (const auto &edge : adjList[node]) {
            if (!visited[edge.target]) {
                s.push(edge.target);
            }
        }
    }
}

std::vector<double> Graph::dijkstra(int startNode) {
    std::vector<double> distances(nodes.size(), std::numeric_limits<double>::infinity());
    distances[startNode] = 0;

    using P = std::pair<double, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P> > pq;
    pq.push(std::make_pair(0.0, startNode));

    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();

        if (dist > distances[node]) continue;

        for (const auto &edge : adjList[node]) {
            double newDist = dist + edge.weight;
            if (newDist < distances[edge.target]) {
                distances[edge.target] = newDist;
                pq.push(std::make_pair(newDist, edge.target));
            }
        }
    }
    return distances;
}

std::vector<double> Graph::pageRank(int iterations, double damping) {
    int n = nodes.size();
    std::vector<double> ranks(n, 1.0 / n);
    std::vector<double> newRanks(n, 0.0);

    for (int it = 0; it < iterations; ++it) {
        for (int i = 0; i < n; ++i) newRanks[i] = (1 - damping) / n;
        for (const auto &[node, edges] : adjList) {
            for (const auto &edge : edges) {
                newRanks[edge.target] += damping * ranks[edge.source] / adjList[edge.source].size();
            }
        }
        ranks = newRanks;
    }
    return ranks;
}

void Graph::calculateCentrality() {
    // Implement centrality calculations
}

