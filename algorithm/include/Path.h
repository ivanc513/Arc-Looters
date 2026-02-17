#pragma once
#include <vector>
#include <utility>
#include <list>
#include "Graph.h"

/*
/ Path carries value and is subject to total_dist constraint
*/
class Path {
private:
    std::vector<std::pair<int,int>> edges;
    int value = 0;
    int total_dist = 0;

public:
    Path(int start_node, int end_node, const Graph& g);

    int get_value() const;
    int get_total_dist() const;

    const std::vector<std::pair<int,int>>& get_edges() const;

    void add_edge_end(int new_node, const Graph& g);
    bool can_add_edge_end(int new_node, const Graph& g, double Tmax) const;
};