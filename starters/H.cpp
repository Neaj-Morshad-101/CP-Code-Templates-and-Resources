// Created by Neaj_Morshad_101
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

///constants
const ll mxn = 200;
const int mod = 1000000007;//1e9+7;

#define endl '\n'
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl

void print(bool ok)
{
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}


///program starts...........

int tc;

int n;
bool g[30][mxn];
int dp[mxn][50];
int vis[mxn][50];

int func(int pos, bool odd)
{
    if (pos >= n - 1)
    {
        return 0;
    }

    if (vis[pos][odd] == tc)
        return dp[pos][odd];

    vis[pos][odd] = tc;

    bool possible = false;


    vector<int> v;

    bool possible_in_first = false;

    if (g[0][pos] and g[0][pos + 1] and g[1][pos] and g[1][pos + 1])
    {
        possible = true;
        possible_in_first = true;
        v.push_back(func(pos + 2, odd ^ 1));
    }
    if (g[2][pos] and g[2][pos + 1] and g[1][pos] and g[1][pos + 1])
    {
        possible = true;
        possible_in_first = true;
        v.push_back(func(pos + 2, odd ^ 1));
    }
    if (g[0][pos + 2] and g[0][pos + 1] and g[1][pos + 2] and g[1][pos + 1])
    {
        possible = true;
        v.push_back(func(pos + 3, odd ^ 1));
    }
    if (g[2][pos + 2] and g[2][pos + 1] and g[1][pos + 2] and g[1][pos + 1])
    {
        possible = true;
        v.push_back(func(pos + 3, odd ^ 1));
    }

    if (!possible)
    {
        return dp[pos][odd] = func(pos + 2, odd);
    }


    if (!possible_in_first)
    {
        if (g[0][pos + 2] and g[0][pos + 3] and g[1][pos + 2] and g[1][pos + 3])
        {
            possible = true;
            v.push_back(func(pos + 4, odd ^ 1));
        }
        if (g[2][pos + 2] and g[2][pos + 3] and g[1][pos + 2] and g[1][pos + 3])
        {
            possible = true;
            v.push_back(func(pos + 4, odd ^ 1));
        }
    }

    int oo = -1, ee = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] & 1) ee = v[i] + 1;
        else oo = v[i] + 1;
    }

    if (pos == 0 and oo != -1)return oo;

    if (odd and ee != -1)
    {
        return dp[pos][odd] = ee;
    }
    if ((!odd) and oo != -1)
    {
        return dp[pos][odd] = oo;
    }

    int val = -1;
    if (oo != -1) val = oo;
    else val = ee;

    return dp[pos][odd] = val;

}

char ch[mxn];

void solve_case()
{
    cin >> n;
    memset(g, false, sizeof g);
    for (int i = 0; i < 3; i++)
    {
        cin >> ch;
        for (int j = 0; j < n; j++)
        {
            if (ch[j] == 'O') g[i][j] = 1;
            else g[i][j] = 0;
        }
    }


    int ok = func(0, 1);

    cout << "Case " << tc << ": ";
    if (ok & 1)
    {
        cout << "Jhinuk" << endl;
    }
    else
    {
        cout << "Grandma" << endl;
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

