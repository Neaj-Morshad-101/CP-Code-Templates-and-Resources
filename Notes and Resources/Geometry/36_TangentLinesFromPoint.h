#pragma once

#include "Point.h"

// tangent lines from point q to the circle
int tangent_lines_from_point(PT p, double r, PT q, line &u, line &v) {
    int x = sign(dist2(p, q) - r * r);
    if (x < 0) return 0; // point in cricle
    if (x == 0) { // point on circle
        u = line(q, q + rotateccw90(q - p));
        v = u;
        return 1;
    }
    double d = dist(p, q);
    double l = r * r / d;
    double h = sqrt(r * r - l * l);
    u = line(q, p + ((q - p).truncate(l) + (rotateccw90(q - p).truncate(h))));
    v = line(q, p + ((q - p).truncate(l) + (rotatecw90(q - p).truncate(h))));
    return 2;
}
