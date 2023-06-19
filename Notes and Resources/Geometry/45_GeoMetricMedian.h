#pragma once

#include "Point.h"

// it returns a point such that the sum of distances
// from that point to all points in p  is minimum // O(n log^2 MX)
PT geometric_median(vector<PT> p) {
    auto tot_dist = [&](PT z) {
        double res = 0;
        for (int i = 0; i < p.size(); i++) res += dist(p[i], z);
        return res;
    };
    auto findY = [&](double x) {
        double yl = -1e5, yr = 1e5;
        for (int i = 0; i < 60; i++) {
            double ym1 = yl + (yr - yl) / 3;
            double ym2 = yr - (yr - yl) / 3;
            double d1 = tot_dist(PT(x, ym1));
            double d2 = tot_dist(PT(x, ym2));
            if (d1 < d2) yr = ym2;
            else yl = ym1;
        }
        return pair<double, double> (yl, tot_dist(PT(x, yl)));
    };
    double xl = -1e5, xr = 1e5;
    for (int i = 0; i < 60; i++) {
        double xm1 = xl + (xr - xl) / 3;
        double xm2 = xr - (xr - xl) / 3;
        double y1, d1, y2, d2;
        auto z = findY(xm1); y1 = z.first; d1 = z.second;
        z = findY(xm2); y2 = z.first; d2 = z.second;
        if (d1 < d2) xr = xm2;
        else xl = xm1;
    }
    return {xl, findY(xl).first };
}
