//https://www.codechef.com/KA19MOS/problems/FCIPL
// Created by Neaj_Morshad_101
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

///define constant
const ll mxn = 105;
const int mod = 998244353;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........

ll add(ll a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}
ll sub(ll a, ll b)
{
    a -= b;
    if (a < 0)a += mod;
    return a;
}
ll mul(ll a, ll b) {
    return a * 1ll * b % mod;
}


int tc;

int dpf[mxn][mxn];
bool visf[mxn][mxn];

int dpc[mxn][mxn];
bool visc[mxn][mxn];


// Stirling number of the second kind ( or Stirling partition number)
// is the number of ways to partition a set of n objects (labelled) into k non - empty subsets(unlebelled)
// O(n * k) for all possible (n, k), for O(n * log(n)) type complexity use NTT see ash's library or druboo vai's library
int f(int n, int k)
{
    if (k == 0) return n == 0;
    if (n == 0 ) return 0;
    //if (n == k) return 1;
    if (visf[n][k]) return dpf[n][k];

    visf[n][k] = true;

    //two cases for person 1, signle or with some-one

    return dpf[n][k] = add(f(n - 1, k - 1), mul(f(n - 1, k), k));
}

//modification: set's size must be at-least 2
// Stirling number of the second kind ( or Stirling partition number)
// is the number of ways to partition a set of n objects (labelled) into k non - empty subsets(unlebelled)
int c(int n, int k)
{
    if (k == 0) return n == 0;
    if (n <= 0) return 0;
    //if (2 * k == n) return 1;
    if (visc[n][k]) return dpc[n][k];

    visc[n][k] = true;

    //two cases for person 1: 2-people or multiple people
    return dpc[n][k] = add( mul((n - 1), c(n - 2, k - 1)), mul(c(n - 1, k), k) );
}



void solve_case()
{
    int F, C, R;
    cin >> F >> C >> R;

    ll ans = 0;

    for (int r = 1; r <= R; r++)
    {
        ans = add(ans, mul(f(F, r), c(C, R - r)));
    }

    cout << ans << endl;

    return;
}

int main()
{
    faster_io;
    memset(visf, false, sizeof visf);
    memset(visc, false, sizeof visc);

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

