#pragma once

#include "Point.h"

int tangents_lines_from_circle(PT c1, double r1, PT c2, double r2, bool inner, line &u, line &v) {
    if (inner) r2 = -r2; // returns outer tangents line of two circles
    PT d = c2 - c1; // if inner == 1 it returns inner tangent lines
    double dr = r1 - r2, d2 = d.norm(), h2 = d2 - dr * dr;
    if (d2 == 0 || h2 < 0) {
        assert(h2 != 0);
        return 0;
    }
    vector<pair<PT, PT>>out;
    for (int tmp : { -1, 1}) {
        PT v = (d * dr + rotateccw90(d) * sqrt(h2) * tmp) / d2;
        out.push_back({c1 + v * r1, c2 + v * r2});
    }
    u = line(out[0].first, out[0].second);
    if (out.size() == 2) v = line(out[1].first, out[1].second);
    return 1 + (h2 > 0);
}
