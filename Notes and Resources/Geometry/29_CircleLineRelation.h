#pragma once

#include "Point.h"
#include "DistFromPointToLine"

int circle_line_relation(PT p, double r, PT a, PT b) {
    double d = dist_from_point_to_line(a, b, p);
    if (sign(d - r) < 0) return 2; // if inside circle
    if (sign(d - r) == 0) return 1; // if on circumference
    return 0; // if outside
}
