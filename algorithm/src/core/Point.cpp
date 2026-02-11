#include "Point.h"
#include <cmath>

double euclidean_distance(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return std::hypot(dx, dy);
}