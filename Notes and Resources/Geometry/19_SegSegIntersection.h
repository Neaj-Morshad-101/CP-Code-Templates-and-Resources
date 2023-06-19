#pragma once

#include "Point.h"

// intersection point between segment ab and segment cd assuming unique intersection exists
bool seg_seg_intersection(PT a, PT b, PT c, PT d, PT &ans) {
    double oa = cross2(c, d, a), ob = cross2(c, d, b);
    double oc = cross2(a, b, c), od = cross2(a, b, d);
    if (oa * ob < 0 && oc * od < 0) {
        ans = (a * ob - b * oa) / (ob - oa);
        return 1;
    }
    else return 0;
}
