// tests/test_ellipse.cpp
#include <gtest/gtest.h>
#include "Graph.h"
#include "Point.h"
#include "steps/EllipseInit.h"

TEST(EllipseTest, InsideEllipseWorks) {
    Point start{0, 0};
    Point end{10, 0};
    Point inside{5, 0};
    Point outside{15, 0};

    double Tmax = 12.0;

    EXPECT_TRUE(Solver::inside_ellipse(inside, start, end, Tmax));
    EXPECT_FALSE(Solver::inside_ellipse(outside, start, end, Tmax));
}

TEST(EllipseTest, EllipseInitRemovesEdges) {
    Point start = {0, 0};
    Point end = {10, 0};
    std::vector<Point> plane = {start, {5,0}, {15, 0}, end};
    std::vector<int> values = {1, 1, 1, 1};
    Graph graph(plane, values);

    double Tmax = euclidean_distance(start, end);
    Graph new_graph = Solver::ellipse_init(graph, plane, Tmax);

    // vertex 1 is inside ellipse, edges to 0 and 2 should be removed
    EXPECT_FALSE(new_graph.has_edge(2, 0));
    EXPECT_FALSE(new_graph.has_edge(2, 3));

    // edges between vertices outside ellipse remain
    EXPECT_TRUE(new_graph.has_edge(1, 0));
    EXPECT_TRUE(new_graph.has_edge(1, 3));
}
