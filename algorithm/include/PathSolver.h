#pragma once

#include "Path.h"
#include "Graph.h"
#include "Point.h"

namespace Solver {
    Path path_solver(const Graph& graph, const std::vector<Point>& plane, double Tmax);
}
