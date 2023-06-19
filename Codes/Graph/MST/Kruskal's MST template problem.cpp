// Created by Neaj_Morshad_101
//https://lightoj.com/problem/civil-and-evil-engineer
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

struct dsu {
    vector<int> par, rnk, size; int c;
    dsu(int n) : par(n + 1), rnk(n + 1, 0), size(n + 1, 1), c(n) {
        for (int i = 0; i <= n; ++i) par[i] = i;
    }
    int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
    bool same(int i, int j) { return find(i) == find(j); }
    int get_size(int i) { return size[find(i)]; }
    int count() { return c; } //connected components
    int merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return -1; else --c;
        if (rnk[i] > rnk[j]) swap(i, j);
        par[i] = j; size[j] += size[i];
        if (rnk[i] == rnk[j]) rnk[j]++;
        return j;
    }
};



void solve_case()
{
    int n; cin >> n;
    vector<array<int, 3>> ed;
    vector<array<int, 3>> ed_neg;
    for ( ; true; ) {
        int u, v, w; cin >> u >> v >> w;
        if (u == v) break;
        ed.push_back({w, u , v});
        ed_neg.push_back({ -w, u, v});
    }
    sort(ed.begin(), ed.end());
    sort(ed_neg.begin(), ed_neg.end());


    long long ans = 0;
    dsu d(n);
    for (auto e : ed) {
        int u = e[1], v = e[2], w = e[0];
        if (d.same(u, v)) continue;
        ans += w;
        d.merge(u, v);
    }
    //cout << "Min : " << ans << endl;


    long long ans2 = 0;
    dsu d2(n);
    for (auto e : ed_neg)
    {
        int u = e[1], v = e[2], w = -e[0];
        //watch3(u, v, w);
        if (d2.same(u, v))
        {
            //cout << "same component already" << endl;
            continue;
        }
        ans2 += w;
        //watch2(w, ans);
        d2.merge(u, v);
    }

    long long sum  = ans + ans2;

    cout << "Case " << tc << ": ";

    if (sum % 2 == 0)
        cout << sum / 2 << '\n';
    else
    {
        cout << sum << "/" << 2 << endl;
    }

    // watch(ans);


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

