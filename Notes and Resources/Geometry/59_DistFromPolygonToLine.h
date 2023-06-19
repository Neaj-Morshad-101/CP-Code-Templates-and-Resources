#pragma once

#include "Point.h"
#include "ExtremeVertex.h"
#include "DistFromPointToLine"

// minimum distance from convex polygon p to line ab
// returns 0 is it intersects with the polygon
// top-upper right vertex
double dist_from_polygon_to_line(vector<PT> &p, PT a, PT b, int top) { //O(log n)
    PT orth = (b - a).perp();
    if (orientation(a, b, p[0]) > 0) orth = (a - b).perp();
    int id = extreme_vertex(p, orth, top);
    if (dot(p[id] - a, orth) > 0) return 0.0; //if orth and a are in the same half of the line, then poly and line intersects
    return dist_from_point_to_line(a, b, p[id]); //does not intersect
}
