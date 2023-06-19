#pragma once

#include "Point.h"
#include "AngleBisector.h"
#include "DistFromPointToSeg.h"

// it assumes point does not lie strictly inside the polygon
double dist_from_point_to_polygon(vector<PT> &v, PT p) { // O(log n)
    int n = (int)v.size(); // minimum distance from a point to a convex polygon
    if (n <= 3) {
        double ans = inf;
        for (int i = 0; i < n; i++) ans = min(ans, dist_from_point_to_seg(v[i], v[(i + 1) % n], p));
        return ans;
    }
    PT bscur, bs = angle_bisector(v[n - 1], v[0], v[1]);
    int ok,  i,  pw = 1,  ans = 0,  sgncur,  sgn = sign(cross(bs, p - v[0]));
    while (pw <= n) pw <<= 1;
    while ((pw >>= 1)) {
        if ((i = ans + pw) < n) {
            bscur = angle_bisector(v[i - 1], v[i], v[(i + 1) % n]);
            sgncur = sign(cross(bscur, p - v[i]));
            ok = sign(cross(bs, bscur)) >= 0 ? (sgn >= 0 || sgncur <= 0) : (sgn >= 0 && sgncur <= 0);
            if (ok) ans = i, bs = bscur, sgn = sgncur;
        }
    }
    return dist_from_point_to_seg(v[ans], v[(ans + 1) % n], p);
}
