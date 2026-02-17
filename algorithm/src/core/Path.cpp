#include "Path.h"
#include "Graph.h" // Needed to access Graph methods

// Constructor: initializes path with start and end node
Path::Path(int start_node, int end_node, const Graph& g) {
    edges.emplace_back(start_node, end_node);
    value = 0;
    total_dist = g.get_edge(start_node, end_node);
}

// Returns true if new_node can be added at the end without exceeding Tmax
bool Path::can_add_edge_end(int new_node, const Graph& g, double Tmax) const {
    auto [u, v] = edges.back(); // last edge
    int delta = -g.get_edge(u, v) + g.get_edge(u, new_node) + g.get_edge(new_node, v);
    return (total_dist + delta <= Tmax);
}

// Adds new_node at the end, updating edges, value, and total_dist
void Path::add_edge_end(int new_node, const Graph& g) {
    auto [u, v] = edges.back(); // last edge

    int delta_dist = -g.get_edge(u, v) + g.get_edge(u, new_node) + g.get_edge(new_node, v);
    int delta_value = g.get_score(new_node);

    total_dist += delta_dist;
    value += delta_value;

    edges.back().second = new_node;
    edges.emplace_back(new_node, v);
}

const std::vector<std::pair<int,int>>& Path::get_edges() const {
    return edges;
}

int Path::get_value() const { return value; }
int Path::get_total_dist() const { return total_dist; }