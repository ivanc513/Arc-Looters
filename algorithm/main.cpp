#include "Path.h"
#include "Graph.h"
#include "PathSolver.h"
#include "steps/EllipseInit.h"
#include <iostream>

int main() {
    // Assume points are in x-sorted order with y-coord tie breaker when passed to cpp
    std::vector<Point> points = {
        {0,0}, {1,0}, {1,1}, {0,1}
    };
    std::vector<int> values = {
        1, 1, 1, 2
    };

    // Assume distance left to travel is given
    double Tmax = 10;

    // Create Graph
    Graph graph(points, values);

    graph.display();

    Graph new_g = Solver::ellipse_init(graph, points, Tmax);
}
