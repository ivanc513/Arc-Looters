#include <vector>
#include <iostream>
#include <cmath>
#include "Graph.h"

Graph::Graph(const std::vector<Point>& nodes, const std::vector<int>& values) 
    : n(nodes.size()), scores(values), adjMatrix(n, std::vector<double>(n, 0.0)) {

    for (int i { 0 }; i < n; ++i) {
        for (int j { 0 }; j < n; ++j) {
            if (i != j) { // No node has an edge to itself
                adjMatrix[i][j] = euclidean_distance(nodes[i], nodes[j]);
            }
        }
    }
}

int Graph::size() const {
    return n;
}

void Graph::remove_edge(int a, int b) {
    adjMatrix[a][b] = 0.0;
    adjMatrix[b][a] = 0.0;
}

bool Graph::has_edge(int a , int b) const {
    return adjMatrix[a][b] > 0;
}

int Graph::get_edge(int a , int b) const {
    return adjMatrix[a][b];
}

int Graph::get_score(int a) const {
    return scores[a];
}

void Graph::display() const {
    for (const auto& row : adjMatrix) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

