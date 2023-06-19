// Created by Neaj_Morshad_101
Template Problem
https://www.spoj.com/problems/QTREE2/
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

///define constant
const ll mxn = 200005;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........

int tc;

const int N = 1e4 + 9, LG = 18;

vector<pair<int, int>> g[N];
int par[N][LG + 1], dep[N], sz[N], distance_[N];
void dfs(int u, int p = 0, int d = 0) {
    par[u][0] = p;
    distance_[u] = d;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto [v, w] : g[u])
        if (v != p) {
            dfs(v, u, d + w);
            sz[u] += sz[v];
        }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
    if (u == v) return u;
    for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
    return par[u][0];
}
int kth(int u, int k) {
    assert(k >= 0);
    for (int i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
    return u;
}
int dist(int u, int v) {
    int l = lca(u, v);
    return dep[u] + dep[v] - (dep[l] << 1);
}
int getdistance_(int u, int v)
{
    int l = lca(u, v);
    return distance_[u] + distance_[v] - 2 * distance_[l];
}
//kth node from u to v, 0th node is u
int go(int u, int v, int k) {
    int l = lca(u, v);
    int d = dep[u] + dep[v] - (dep[l] << 1);
    assert(k <= d);
    if (dep[l] + k <= dep[u]) return kth(u, k);
    k -= dep[u] - dep[l];
    return kth(v, dep[v] - dep[l] - k);
}



void solve_case()
{
    int n;
    cin >> n;

    //*** 0 indexed
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1);

    // int q;
    // cin >> q;

    // cout << "Case " << tc << ":" << endl;

    while (true)
    {
        string s;
        cin >> s;
        if (s == "DONE")
        {
            break;
        }
        int u, v;
        cin >> u >> v;
        if (s == "DIST")
        {
            cout << getdistance_(u, v) << endl;
        }
        else
        {
            int k;
            cin >> k;
            cout << go(u, v, k - 1) << endl;

        }
    }


    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
    }
    //extra blank line
    cout << endl;


    return;
}

int main()
{
    faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int total_test = 1;
    cin >> total_test;
    for (int test_case = 1; test_case <= total_test; test_case++)
    {
        tc = test_case;
        solve_case();
    }
///  KeyPoint


///  Corner Cases




    return 0;
}

