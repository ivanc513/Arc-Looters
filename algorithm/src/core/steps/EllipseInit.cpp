#include "steps/EllipseInit.h"

bool Solver::inside_ellipse(const Point&p, const Point& start, const Point& end, double Tmax) {
    double d1 = euclidean_distance(p, start);
    double d2 = euclidean_distance(p, end);

    return (d1 + d2) <= Tmax;
}

Graph Solver::ellipse_init(const Graph& graph, const std::vector<Point> plane, double Tmax) {
    Graph new_graph = graph;
    for (int i { 1 }; i < plane.size() - 1; ++i) {
        if (!inside_ellipse(plane[i], plane.front(), plane.back(), Tmax)) {
            new_graph.remove_edge(i, 0);
            new_graph.remove_edge(i, plane.size() - 1);
        }
    }

    return new_graph;
}