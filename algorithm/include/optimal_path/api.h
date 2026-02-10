// include/optimal_path/api.h
#pragma once
#include "types.h"

extern "C" {

// Returns number of edges written into out_edges
OPTIMALPATH_API int compute_optimal_path(
    const Point2D* points,   // input points array
    int point_count,         // number of points
    Edge* out_edges,         // pre-allocated array for edges
    int max_edges            // max edges out_edges can hold
);

}
