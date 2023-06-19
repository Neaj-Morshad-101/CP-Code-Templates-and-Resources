#pragma once

#include "Point.h"

int circle_circle_relation(PT a, double r, PT b, double R) {
    double d = dist(a, b);
    if (sign(d - r - R) > 0)  return 5;//outside and do not intersect
    if (sign(d - r - R) == 0) return 4;//intersect outside in one point
    double l = fabs(r - R);
    if (sign(d - r - R) < 0 && sign(d - l) > 0) return 3;//intersect in 2 points
    if (sign(d - l) == 0) return 2;//intersect inside in one point
    if (sign(d - l) < 0) return 1;//inside and do not intersect
    assert(0); return -1;
}
