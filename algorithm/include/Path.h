#pragma once
#include <vector>
#include <utility>

class Path {
public:
    int value;
    std::vector<std::pair<int,int>> edges;

    void add_edge(int a, int b);
};