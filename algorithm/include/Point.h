#pragma once

class Point {
public:
    int x;
    int y;

    Point() : x(0), y(0) {}
    Point(int x_, int y_): x(x_), y(y_) {}

    friend double euclidean_distance(const Point& a, const Point& b);
};

