#pragma once

#include "Point.h"

int point_line_relation(PT a, PT b, PT p) {
    int c = sign(cross(p - a, b - a));
    if (c < 0) return 1; // if point is ccw
    if (c > 0) return 2; // if point is cw to the line
    return 3; // if point is on the line
}
