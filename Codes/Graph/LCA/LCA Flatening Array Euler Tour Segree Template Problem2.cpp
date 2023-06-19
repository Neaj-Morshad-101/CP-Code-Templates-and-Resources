// Created by Neaj_Morshad_101
//Flatening Array
//Euler Tour
//Segment Tree
//LCA
//Char Frequency Query with update
https://www.hackerrank.com/contests/srbd-code-contest-2022-round-2-retake/challenges/answer-the-queries-4
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
int time_;
int arr[mxn];


const int N = 2e5 + 9, LG = 18;

vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N], st[N], ed[N], euler_tour[N];
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

int val_(char ch)
{
    if (ch >= 'a' and ch <= 'z')
    {
        return (int)(ch - 'a') + 1;
    }
    else if (ch >= 'A' and ch <= 'Z')
    {
        return (int)(ch - 'A' + 26) + 1;
    }
    else return (int)(ch - '0' + 52) + 1;
}

#define Left (node*2)
#define Right (node*2+1)
#define Mid ((b+e)/2)


int n;

vector<int> tree[4 * mxn]; // for N size arary segment tree contains 2N-1 nodes if N is a power of 2. so max size will be 4*N (we need to make N a power of 2)

//Merge complexity will be multiplied by each of the complexity of build, update and query
//Merging Two Nodes Data
vector<int> Merge(vector<int> a, vector<int> b)
{
    vector<int> v(63, 0);
    for (int i = 1; i < 63; i++)
    {
        v[i] = a[i] + b[i];
    }
    return v; /// *** may change depending on the problem...
}

//O(N) because number of nodes in the segment tree is 2*N.
void build(int node, int b, int e) //current node and node's range (begin to end)
{
    if (b == e)
    {
        vector<int> v(63, 0);

        if (euler_tour[b] > 0)
        {
            v[euler_tour[b]] = 1;
        }
        else v[(-euler_tour[b])] = -1;

        tree[node] = v;
        return;
    }

    build(Left, b, Mid);
    build(Right, Mid + 1, e);

    tree[node] = Merge(tree[Left], tree[Right]);
}

//O(4*log(N))     at most four nodes are visited in the segment tree.
vector<int> query(int node, int b, int e, int l, int r) //current node and node's range (begin to end) and query range (l to r)
{
    if (l <= b and e <= r)
    {
        return tree[node];
    }
    if (b > r or e < l)
    {
        vector<int> v(63, 0);
        return v; /// *** may change depending on the problem...
    }

    vector<int> x = query(Left, b, Mid, l, r);
    vector<int> y = query(Right, Mid + 1, e, l, r);

    return Merge(x, y);

}

//O(log(N))
void update(int node, int b, int e, int i, ll val) // current node and node's range (begin to end) and update on index i with value val ( arr[i] = val )
{
    if (i > e || i < b) return;
    if (b == e)
    {
        vector<int> v(63, 0);
        if (val > 0)v[val] = 1;
        else {
            v[-val] = -1;
        }
        tree[node] = v; /// *** may change depending on the problem...
        return;
    }
    update(Left, b, Mid, i, val);
    update(Right, Mid + 1, e, i, val);


    tree[node] = Merge(tree[Left], tree[Right]);
}

char s[mxn];

void solve_case()
{
    time_ = 1;
    //cin >> n;
    int q; //cin >> q;
    scanf("%d%d%s", &n, &q, s);

    for (int i = 1; i <= n; i++)
    {
        arr[i] = val_(s[i - 1]);
    }

    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        euler_tour[st[i]] = arr[i];
        //cout << st[i] << " " << ed[i] << endl;
        euler_tour[ed[i]] = -arr[i];
    }


    build(1, 1, 2 * n);


    while (q--)
    {
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            int i, j;
            scanf("%d%d", &i, &j);
            int lca_ = lca(i, j);

            vector<int> d1, d2, val_lca;
            d1 = query(1, 1, 2 * n, st[lca_], st[i]);
            d2 = query(1, 1, 2 * n, st[lca_], st[j]);
            val_lca = query(1, 1, 2 * n, st[lca_], st[lca_]);
            vector<int> d = Merge(d1, d2);
            for (int i = 1; i < 63; i++) d[i] -= val_lca[i];

            bool ok = true;
            int val = 0;

            for (int i = 1; i < 63; i++)
            {
                if (d[i]) {
                    if (val) {
                        if (val != d[i]) {
                            ok = 0;
                            break;
                        }
                    }
                    else val = d[i];
                }
            }
            if (ok)
            {
                printf("Yes\n");
            }
            else printf("No\n");

        }
        else
        {
            int i;
            char c;

            scanf("%d %c", &i, &c);
            int v = val_(c);
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
    // faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int total_test = 1;
    //cin >> total_test;
    for (int test_case = 1; test_case <= total_test; test_case++)
    {
        tc = test_case;
        solve_case();
    }
///  KeyPoint


///  Corner Cases




    return 0;
}

