#pragma once

#include <vector>
#include "Point.h"

// Undirected Graph
class Graph {
private:
    int n;
    std::vector<int> scores;
    std::vector<std::vector<double>> adjMatrix;
public:
    Graph(const std::vector<Point>& nodes, const std::vector<int>& values);

    void remove_edge(int a, int b);

    bool has_edge(int a, int b) const;
    
    int get_edge(int a, int b) const;

    int get_score(int a) const;

    int size() const;

    void display() const;
};