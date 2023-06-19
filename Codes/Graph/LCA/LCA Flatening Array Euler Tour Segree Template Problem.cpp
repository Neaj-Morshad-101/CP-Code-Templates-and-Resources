// Created by Neaj_Morshad_101
//Flatening Array
//Euler Tour
//Segment Tree
//LCA
//
https://lightoj.com/problem/aladdin-and-the-return-journe
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

///define constant
const ll mxn = 60004;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........

int tc;
int time_;
int arr[mxn];


const int N = 6e4 + 9, LG = 18;

vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N], st[N], ed[N], euler_tour[2 * N];
void dfs(int u, int p = 0) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    st[u] = time_++;
    for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto v : g[u])
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }

    ed[u] = time_++;
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
    if (u == v) return u;
    for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
    return par[u][0];
}

#define Left (node*2)
#define Right (node*2+1)
#define Mid ((b+e)/2)


int n;

ll tree[4 * mxn]; // for N size arary segment tree contains 2N-1 nodes if N is a power of 2. so max size will be 4*N (we need to make N a power of 2)

//Merge complexity will be multiplied by each of the complexity of build, update and query
//Merging Two Nodes Data
ll Merge(ll a, ll b)
{
    return a + b; /// *** may change depending on the problem...
}

//O(N) because number of nodes in the segment tree is 2*N.
void build(int node, int b, int e) //current node and node's range (begin to end)
{
    if (b == e)
    {
        tree[node] = euler_tour[b];
        return;
    }

    build(Left, b, Mid);
    build(Right, Mid + 1, e);

    tree[node] = Merge(tree[Left], tree[Right]);
}

//O(4*log(N))     at most four nodes are visited in the segment tree.
ll query(int node, int b, int e, int l, int r) //current node and node's range (begin to end) and query range (l to r)
{
    if (l <= b and e <= r)
    {
        return tree[node];
    }
    if (b > r or e < l)
    {
        return 0; /// *** may change depending on the problem...
    }

    ll x = query(Left, b, Mid, l, r);
    ll y = query(Right, Mid + 1, e, l, r);

    return Merge(x, y);

}

//O(log(N))
void update(int node, int b, int e, int i, ll val) // current node and node's range (begin to end) and update on index i with value val ( arr[i] = val )
{
    if (i > e || i < b) return;
    if (b == e)
    {
        tree[node] = val; /// *** may change depending on the problem...
        return;
    }

    update(Left, b, Mid, i, val);
    update(Right, Mid + 1, e, i, val);


    tree[node] = Merge(tree[Left], tree[Right]);
}



void solve_case()
{
    time_ = 1;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x++; y++;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        euler_tour[st[i]] = arr[i];
        euler_tour[ed[i]] = -arr[i];
    }
    // for (int i = 1; i <= 2 * n; i++)
    // {
    //     cout << euler_tour[i] << " ";
    // }
    // cout << endl;

    build(1, 1, 2 * n);
    // for (int i = 1; i <= 2 * n; i++)
    // {
    //     cout << query(1, 1, 2 * n, i, i) << " ";
    // }
    // cout << endl;

    int q;
    cin >> q;

    cout << "Case " << tc << ":" << endl;

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int i, j;
            cin >> i >> j;
            i++; j++;
            int lca_ = lca(i, j);

            int d1, d2, val_lca;
            d1 = query(1, 1, 2 * n, st[lca_], st[i]);
            d2 = query(1, 1, 2 * n, st[lca_], st[j]);
            val_lca = query(1, 1, 2 * n, st[lca_], st[lca_]);
            //watch3(d1, d2, val_lca);

            cout << d1 + d2 - val_lca << endl;

        }
        else
        {
            int i, v;

            cin >> i >> v;
            i++;
            //watch2(i, v);
            update(1, 1, 2 * n, st[i], v);
            update(1, 1, 2 * n, ed[i], -v);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
    }

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

