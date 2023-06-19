// Created by Neaj_Morshad_101
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


ll mul(ll a, ll b) {
    return a * 1ll * b;
}

int tc;

ll dp[mxn];
bool vis[mxn];

//De-arrangement : d(n)
ll d(int n)
{
    if (n == 1) return 0;
    if (n == 0) return 1;

    if (vis[n]) return dp[n];

    vis[n] = true;

    return dp[n] = mul(n - 1, d(n - 2) + d(n - 1));
}

ll nCr(ll n, ll r)
{
    ll ans = 1;
    for (int i = 0; i < r; i++)
    {
        ans *= (n - i);
        ans /= (i + 1);
    }

    return ans;
}


void solve_case()
{
    int n;
    cin >> n;
    int k; cin >> k;

    ll ans = 0;

    for (int m = 0; m <= k; m++)
    {
        ans += (nCr(n, m) * d(m));
    }

    cout << ans << endl;



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

