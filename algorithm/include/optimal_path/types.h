// include/optimal_path/types.h
#pragma once

#ifdef _WIN32
  #ifdef OPTIMALPATH_EXPORTS
    #define OPTIMALPATH_API __declspec(dllexport)
  #else
    #define OPTIMALPATH_API __declspec(dllimport)
  #endif
#else
  #define OPTIMALPATH_API
#endif

extern "C" {

struct Point2D {
    double x;
    double y;
};

struct Edge {
    int from;  // index of starting point
    int to;    // index of ending point
};

}
