#include "PathSolver.h"
#include "steps/EllipseInit.h"
#include "steps/PathInit.h"

Path Solver::path_solver(const Graph& graph, const std::vector<Point>& plane, double Tmax) {
    Graph new_graph = Solver::ellipse_init(graph, plane, Tmax); // Remove all edges to a point outside of the ellipse

    Path new_path(0, 2, graph);
    return new_path;
}