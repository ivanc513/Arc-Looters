#include "Path.h"


void Path::add_edge(int a, int b) {
    std::pair p(a,b);
    edges.emplace_back(p);
}


