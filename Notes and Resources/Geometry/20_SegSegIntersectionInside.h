#pragma once

#include "Point.h"
#include "IsPointOnSegment.h"
#include "SegSegIntersection.h"

// intersection point between segment ab and segment cd assuming unique intersection may not exists
// se.size()==0 for no intersection,1 for one intersection,2 for range intersection
set<PT> seg_seg_intersection_inside(PT a,  PT b,  PT c,  PT d) {
    PT ans;
    if (seg_seg_intersection(a, b, c, d, ans)) return {ans};
    set<PT> se;
    if (is_point_on_seg(c, d, a)) se.insert(a);
    if (is_point_on_seg(c, d, b)) se.insert(b);
    if (is_point_on_seg(a, b, c)) se.insert(c);
    if (is_point_on_seg(a, b, d)) se.insert(d);
    return se;
}
