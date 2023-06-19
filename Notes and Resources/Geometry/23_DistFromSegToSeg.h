#pragma once

#include "Point.h"
#include "SegSegIntersection"
#include "DistanceFromPointToSegment"

// minimum distance from segment ab to segment cd
double dist_from_seg_to_seg(PT a, PT b, PT c, PT d) {
    PT dummy;
    if (seg_seg_intersection(a, b, c, d, dummy)) return 0.0;
    else return min({dist_from_point_to_seg(a, b, c), dist_from_point_to_seg(a, b, d),
                         dist_from_point_to_seg(c, d, a), dist_from_point_to_seg(c, d, b)
                        });
}
