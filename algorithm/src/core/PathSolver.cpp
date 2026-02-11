#include "PathSolver.h"
#include "steps/EllipseInit.h"

Path Solver::path_solver(const Graph& graph, const std::vector<Point>& plane, double Tmax) {
    Graph new_graph = Solver::ellipse_init(graph, plane, Tmax); // Remove all edges to a point outside of the ellipse

    Path new_path;

    new_path.value = 0;
    new_path.edges.emplace_back(1,1);

    return new_path;
}