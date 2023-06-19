#pragma once

#include "Point.h"

bool get_direction(vector<PT> &p) {
    double ans = 0; int n = p.size();
    for (int i = 0; i < n; i++) ans += cross(p[i], p[(i + 1) % n]);
    if (sign(ans) > 0) return 1; // 1 if ccw
    return 0; // 0 if cw
}
