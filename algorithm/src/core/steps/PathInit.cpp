#include "steps/PathInit.h"
#include <algorithm>
#include <numeric>

Path Solver::solution(Path& l, const Graph& graph, double Tmax, int lth) {
    // Greedy sort by score
    int n = graph.size();
    std::vector<int> sorted_points (n - 2);
    std::iota(sorted_points.begin(), sorted_points.end(), 1);
    std::sort(sorted_points.begin(), sorted_points.end(), [&graph, n](const auto& a, const auto& b) {
        return (graph.get_score(a) > graph.get_score(b));
    });

    // Create paths until all nodes have been selected
    std::vector<Path> paths;
    paths.reserve(1);
    paths[0] = l;
    int path_num { 0 };
    for (int i { 1 }; i < n - 1; ++i) {
        int index = sorted_points[i];
        if (index == lth) break; // Already in first path
        if (paths[path_num].can_add_edge_end(index, graph, Tmax)) {
            // Init new path
            Path new_path (0, graph.size() - 1, graph);
            paths.emplace_back(new_path);
            ++path_num;
        } else {
            paths[path_num].add_edge_end(index, graph);
        }
    }

    auto best = std::max_element(paths.begin(), paths.end(), 
        [](const auto& p1, const auto& p2) {
            return p1.get_value() > p2.get_value(); 
        });

    l = *best;
    return l;
}

std::vector<Path> Solver::paths_init(const Graph& graph, double Tmax) {
    // Sort by largest distance from start and end
    int n = graph.size();
    std::vector<int> sorted_points(n - 2); // Contains node indices from graph (exclude start & end)
    std::iota(sorted_points.begin(), sorted_points.end(), 1);
    std::sort(sorted_points.begin(), sorted_points.end(), [&graph, n](const auto& a, const auto& b) {
        return (graph.get_edge(0, a) + graph.get_edge(a, n - 1) 
            > (graph.get_edge(0, b) + graph.get_edge(b, n - 1))
        );
    });

    std::vector<Path> solutions; 
    solutions.reserve(MAX_ITERATIONS);// max size

    // Create each solution
    for (int i { 0 }; i < sorted_points.size(); ++i) { 
        if (solutions.size() >= MAX_ITERATIONS) break;
        if (graph.has_edge(0, sorted_points[i])) {
            Path p (0, graph.size() - 1, graph);
            p.add_edge_end(sorted_points[i], graph);
            p = solution(p, graph, Tmax, sorted_points[i]);
            solutions.push_back(std::move(p));
        }
    }

    // Sort by score
    std::sort(solutions.begin(), solutions.end(), 
        [](const auto& a, const auto& b) {
            return a.get_value() > b.get_value();
        });

    return solutions;
}