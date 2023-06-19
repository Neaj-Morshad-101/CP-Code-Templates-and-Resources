#pragma once

#include "Point.h"

// find a point from a through b with distance d
PT point_along_line(PT a, PT b, double d) {
    return a + (((b - a) / (b - a).norm()) * d);
}
