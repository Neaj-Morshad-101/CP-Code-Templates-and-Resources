#pragma once

#include "Point.h"

PT angle_bisector(PT &a, PT &b, PT &c) {
    PT p = a - b, q = c - b; // bisector vector of <abc
    return p + q * sqrt(dot(p, p) / dot(q, q));
}
