#pragma once

#include "Point.h"
#include "Graph.h"

namespace Solver {
    bool inside_ellipse(const Point&p, const Point& start, const Point& end, double Tmax);

    Graph ellipse_init(const Graph& graph, const std::vector<Point> plane, double Tmax);
}