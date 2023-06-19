// Created by Neaj_Morshad_101
https://www.codechef.com/problems/WALK4
Time Complexity : O(v ^ 3) * O(log(k));
Number of k - lengh walk / path in a graph
graph may have multiple edges and self loops
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

#define MAX 105
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD * 3;

/* 1 base row columun index */
struct Matrix {
    int row, col;
    ll m[MAX][MAX];
    Matrix() {memset(m, 0, sizeof(m));}
    void Set(int r, int c) {row = r; col = c;}
    Matrix(int r, int c) {memset(m, 0, sizeof(m)); Set(r, c);}
    void normalize() {
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                m[i][j] %= MOD;
                if (m[i][j] < 0) m[i][j] += MOD;
            }
        }
    }
};

Matrix Multiply(Matrix A, Matrix B) {
    Matrix ans(A.row, B.col);

    for (int i = 1; i <= A.row; i++) {
        for (int j = 1; j <= B.col; j++) {
            ans.m[i][j] = 0;
            ll sm = 0;
            for (int k = 1; k <= A.col; k++) {
                sm += (A.m[i][k] * B.m[k][j]);
                if (sm >= MOD2) sm -= MOD2;
            }
            ans.m[i][j] = sm % MOD;
        }
    }
    return ans;
}

Matrix Power(Matrix mat, ll p) {
    Matrix res(mat.row , mat.col);
    Matrix ans(mat.row , mat.col);

    int n = ans.row;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans.m[i][j] = 0;
            res.m[i][j] = mat.m[i][j];
        }
        ans.m[i][i] = 1;
    }

    while (p) {
        if (p & 1) ans = Multiply(ans, res);
        res = Multiply(res, res);
        p = p / 2;
    }
    return ans;
}

int tc;

int n, m;
int g[105][105];

ll countWalk(int x, int k)
{
    Matrix Adj(100, 100);
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if (g[i][j] and g[i][j] <= x)
            {
                Adj.m[i][j] = 1;
            }
        }
    }
    Matrix Adjk = Power(Adj, k);
    ll total_walks = 0;
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            total_walks += Adjk.m[i][j];
        }
    }

    return total_walks;
}


void solve_case()
{
    memset(g, 0, sizeof g);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = w;
        g[v][u] = w;
    }

    ll ans[105] = {0};

    for (int x = 1; x <= 100; x++)
    {
        ans[x] = countWalk(x, 4) - countWalk(x - 1, 4);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }


    return;
}

int main()
{
    faster_io;

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
