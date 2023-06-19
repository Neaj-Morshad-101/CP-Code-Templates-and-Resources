#pragma once

#include "Point.h"

// reflection point c onto line through a and b  assuming a != b
PT reflection_from_point_to_line(PT a, PT b, PT c) {
    PT p = project_from_point_to_line(a, b, c);
    return point_along_line(c, p, 2.0 * dist(c, p));
}
