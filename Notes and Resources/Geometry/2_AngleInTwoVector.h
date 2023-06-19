#pragma once

#include "Point.h"

double get_angle(PT a, PT b) {
    double costheta = dot(a, b) / a.norm() / b.norm();
    return acos(max((double) - 1.0, min((double)1.0, costheta)));
}
