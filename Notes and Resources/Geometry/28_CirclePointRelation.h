#pragma once

#include "Point.h"

int circle_point_relation(PT p, double r, PT b) {
    double d = dist(p, b);
    if (sign(d - r) < 0) return 2; // if inside circle
    if (sign(d - r) == 0) return 1; // if on circumference
    return 0; // if outside
}
