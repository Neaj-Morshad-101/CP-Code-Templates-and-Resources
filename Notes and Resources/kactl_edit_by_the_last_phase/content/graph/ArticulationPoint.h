/**
 * Author: Emil Lenngren, Simon Lindholm
 * Date: 2011-11-29
 * License: CC0
 * Source: folklore
 * Description: Calculates a valid assignment to boolean variables a, b, c,... to a 2-SAT problem, so that an expression of the type $(a\|\|b)\&\&(!a\|\|c)\&\&(d\|\|!b)\&\&...$ becomes true, or reports that it is unsatisfiable.
 * Negated variables are represented by bit-inversions (\texttt{\tilde{}x}).
 * Usage:
 *  TwoSat ts(number of boolean variables);
 *  ts.either(0, \tilde3); // Var 0 is true or var 3 is false
 *  ts.setValue(2); // Var 2 is true
 *  ts.atMostOne({0,\tilde1,2}); // <= 1 of vars 0, \tilde1 and 2 are true
 *  ts.solve(); // Returns true iff it is solvable
 *  ts.values[0..N-1] holds the assigned values to the vars
 * Time: O(N+E), where N is the number of boolean variables, and E is the number of clauses.
 * Status: stress-tested
 */
#pragma once

vector<int>g[mx]; int Time=1;
int articular_point[mx],st[mx],low[mx];
int dfs(int u,int p){
 st[u]=low[u]=Time++; int child=0;
 for(auto it:g[u]) {
  if(it==p)continue;
  if(st[it]==0) {
   child++; dfs(it,u);
   if(st[u]<=low[it])articular_point[u]=1;
   low[u]=min(low[u],low[it]);
  }
  else low[u]=min(low[u],st[it]);
 }
 return child;
}
for(int i=1;i<=n;i++) {
 if(st[i])continue;
 articular_point[i]=(dfs(i,-1)>1);
}
