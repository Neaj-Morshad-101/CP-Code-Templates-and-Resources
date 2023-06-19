/**
 * Author: Simon Lindholm
 * Date: 2015-02-23
 * License: CC0
 * Source: http://en.wikipedia.org/wiki/Bellman-Ford_algorithm
 * Description: Calculates shortest paths from $s$ in a graph that might have negative edge weights.
 * Unreachable nodes get dist = inf; nodes reachable through negative-weight cycles get dist = -inf.
 * Assumes $V^2 \max |w_i| < \tilde{} 2^{63}$.
 * Time: O(VE)
 * Status: Tested on kattis:shortestpath3
 */
#pragma once

typedef double ll;
const int maxn = 105;
const int maxm = 10005;
const ll inf = 1e9;
ll d[maxn],w[maxm];
int u[maxm],v[maxm],n,m;
bool BellmanFord(){//1-indexed
 for(int i=1;i<=n;i++)d[i]=inf;d[1]=0;
 for(int i=1; i<=n; i++)
  for(int j=0; j<m; j++)
   if(d[u[j]]+w[j] < d[v[j]])
    d[v[j]]=d[u[j]]+w[j];
 bool negCycle = false;
 for(int j=0; j<m; j++)
  if(d[u[j]]+w[j] < d[v[j]]) {
   negCycle=true; break;
  }
 return negCycle;
}
