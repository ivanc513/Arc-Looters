#pragma once
#include "Path.h"
#include "Point.h"
#include "Graph.h"

# define MAX_ITERATIONS 10

namespace Solver {
    Path solution(Path& l, const Graph& graph, double Tmax, int lth);

    std::vector<Path> paths_init(const Graph& graph, double Tmax);
}