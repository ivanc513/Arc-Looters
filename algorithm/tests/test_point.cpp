#include <gtest/gtest.h>
#include "Point.h"

TEST(PointTest, DistanceWorks) {
    Point a{0, 0};
    Point b{3, 4};

    EXPECT_DOUBLE_EQ(euclidean_distance(a, b), 5.0);
}
