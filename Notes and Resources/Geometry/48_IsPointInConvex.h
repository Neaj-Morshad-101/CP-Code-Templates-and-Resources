#pragma once

#include "Point.h"

// it must be strictly convex, otherwise make it strictly convex first
int is_point_in_convex(vector<PT> &p, const PT& x) { // O(log n)
    int n = p.size(); assert(n >= 3);
    int a = orientation(p[0], p[1], x), b = orientation(p[0], p[n - 1], x);
    if (a < 0 || b > 0) return 1; // 1 if strictly outside
    int l = 1, r = n - 1;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (orientation(p[0], p[mid], x) >= 0) l = mid;
        else r = mid;
    }
    int k = orientation(p[l], p[r], x);
    if (k <= 0) return -k; 
    if (l == 1 && a == 0) return 0; // 0 if on the polygon
    if (r == n - 1 && b == 0) return 0; // if on the polygon
    return -1;// -1 if strictly inside
}
