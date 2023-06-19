/**
 * Author: Simon Lindholm
 * Date: 2017-04-17
 * License: CC0
 * Source: folklore
 * Description: Finds all biconnected components in an undirected graph, and
 *  runs a callback for the edges in each. In a biconnected component there
 *  are at least two distinct paths between any two nodes. Note that a node can
 *  be in several components. An edge which is not in a component is a bridge,
 *  i.e., not part of any cycle.
 * Usage:
 *  int eid = 0; ed.resize(N);
 *  for each edge (a,b) {
 *    ed[a].emplace_back(b, eid);
 *    ed[b].emplace_back(a, eid++); }
 *  bicomps([\&](const vi\& edgelist) {...});
 * Time: O(E + V)
 * Status: tested during MIPT ICPC Workshop 2017
 */
#pragma once

vector<int>g[mx];int Time=1;int st[mx];
vector<pair<int,int>>Bridge;int low[mx];
void dfs(int u,int p){
 st[u]=low[u]=Time++;int child=0;
 for(auto it:g[u]) {
  if(it==p)continue;
  if(st[it]==0){
   dfs(it,u);
  if(st[u]<low[it])Bridge.push_back({u,it});
  low[u]=min(low[u],low[it]);
  }
  else low[u]=min(low[u],st[it]);
 }
}
