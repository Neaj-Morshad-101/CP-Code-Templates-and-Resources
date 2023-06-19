// Created by Neaj_Morshad_101
// tested :
// https://codeforces.com/problemset/problem/319/C
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

///define constant
const ll mxn = 100005;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........




int tc;

int n;
int a[mxn], b[mxn];


//Offline CHT
ll INF = 9e18 + 5;

struct Line {
    ll m, c;
    Line(ll x, ll y) {m = x; c = y;}
    ll Get(ll x) {return m * x + c;}
    bool operator<(const Line &other) const {return m < other.m;}
};

bool Bad(Line &P, Line &C, Line &N) {
    return (P.c - C.c) * 1.0L * (N.m - P.m) > (P.c - N.c) * 1.0L * (C.m - P.m);
}

//This Convex Hull always maintains lower convex hull
//m1 >= m2 >= m3 .... >= mk
//For Min Query : Add(m,c)
//For Max Query : Add(-m,-c)

struct ConvexHull {
    vector<Line>hull;

    void Add(ll m, ll c) {
        //always maintaining the minimum c in case multiple equal m
        if (hull.size() > 0 && hull.back().m == m) {
            if (hull.back().c > c) hull.pop_back();
            else return;
        }

        hull.push_back(Line(m, c));
        int sz = hull.size();
        while (sz > 2 && Bad(hull[sz - 3], hull[sz - 2], hull[sz - 1])) {
            swap(hull[sz - 2], hull[sz - 1]); hull.pop_back(); sz--;
        }
    }

    ll Query(ll x) {
        int lo = -1;
        int hi = hull.size() - 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (hull[mid].Get(x) >= hull[mid + 1].Get(x)) lo = mid;
            else hi = mid;
        }
        if (hi < 0 || hi >= hull.size()) return INF;
        return hull[hi].Get(x);
    }
};


void solve_case()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int j = 1; j <= n; j++)
    {
        cin >> b[j];
    }

    ll dp[n + 1];

    dp[1] = 0;

    ConvexHull cht;

    for (int i = 2; i <= n; i++)
    {
        cht.Add(b[i - 1], dp[i - 1]);

        dp[i] = cht.Query(a[i]);
    }

    cout << dp[n] << endl;





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

