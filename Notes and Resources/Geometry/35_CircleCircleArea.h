#pragma once

#include "Point.h"

/// returns area of intersection between two circles
double circle_circle_area(PT a, double r1, PT b, double r2) {
    double d = (a - b).norm();
    if (r1 + r2 < d + eps) return 0;
    if (r1 + d < r2 + eps) return PI * r1 * r1;
    if (r2 + d < r1 + eps) return PI * r2 * r2;
    double theta_1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d)),
           theta_2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
    return r1 * r1 * (theta_1 - sin(2 * theta_1) / 2.) + r2 * r2 * (theta_2 - sin(2 * theta_2) / 2.);
}
