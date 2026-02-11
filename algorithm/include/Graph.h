#pragma once

#include <vector>
#include "Point.h"

// Undirected Graph
class Graph {
private:
    int n;
    std::vector<std::vector<double>> adjMatrix;
public:
    Graph(const std::vector<Point>& nodes);

    void remove_edge(int a, int b);

    bool has_edge(int a, int b);

    int size();

    void display();
};