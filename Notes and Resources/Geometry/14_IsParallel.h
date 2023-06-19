#pragma once

#include "Point.h"

bool is_parallel(PT a, PT b, PT c, PT d) {
    double k = fabs(cross(b - a, d - c));
    if (k < eps) {
        if (fabs(cross(a - b, a - c)) < eps && fabs(cross(c - d, c - a)) < eps) return 2;
        else return 1;
    } // 0 if not parallel, 1 if parallel, 2 if collinear
    else return 0;
}
