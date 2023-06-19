#pragma once

#include "Point.h"
#include "CricleStructure"
#include "CircleCircleIntersection"

// returns two circle c1, c2 through points a, b and of radius r
int get_circle(PT a, PT b, double r, circle &c1, circle &c2) {
    vector<PT> v = circle_circle_intersection(a, r, b, r);
    int t = v.size();
    if (!t) return 0; // 0 if there is no such circle
    c1.p = v[0], c1.r = r;
    if (t == 2) c2.p = v[1], c2.r = r;
    return t; // 1 if one circle, 2 if two circle
}
