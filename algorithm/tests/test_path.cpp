#include <gtest/gtest.h>
#include "Graph.h"
#include "Point.h"
#include "Path.h"

TEST(PathTest, PathAddsEdges) {
    std::vector<Point> plane = {{1, 0}, {5,0}, {15, 5}, {20, 0}};
    std::vector<int> scores = {0, 5, 5, 0};
    Graph graph (plane, scores);
    double Tmax = 20;

    Path p(0, 3, graph);

    EXPECT_TRUE(p.can_add_edge_end(1, graph, Tmax));
    p.add_edge_end(1, graph);
    EXPECT_TRUE(p.get_value() == 5);

    EXPECT_FALSE(p.can_add_edge_end(2, graph, Tmax));
}