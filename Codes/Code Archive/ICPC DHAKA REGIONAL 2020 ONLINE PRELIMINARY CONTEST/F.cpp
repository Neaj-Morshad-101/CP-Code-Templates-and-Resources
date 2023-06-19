//correct it by watching this
//https://www.youtube.com/watch?v=qFdSKtDpwuk&ab_channel=AshapBappy



// Created by Neaj_Morshad_101
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

///define constant

///CHECK FOR MXN - 100
const ll mxn = 4000206;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........

int tc;
ll a, b, m, x;


bool isSet(int mask, int bit_pos)
{
    if (mask & (1 << bit_pos)) return true;
    return false;
}


vector <int> prime;
bitset<mxn>is_composite;
void linearSieve (int n) {
    for (int i = 2; i <= n; ++i) {
        if (!is_composite[i]) prime.push_back (i);
        for (int j = 0; j < prime.size () && i * prime[j] <= n; ++j) {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

/// returns count of numbers ranged 1 to n that are coprime with x
ll phi(ll n)
{
    ll phi_n = n;

    //ll sq = sqrtl(n + 100);

    for (int i = 0; i < prime.size() and prime[i] * prime[i] <= n; i++)
    {
        if (n % prime[i] == 0)
        {
            phi_n *= (prime[i] - 1);
            phi_n /= prime[i];

            while (n % prime[i] == 0)
            {
                n /= prime[i];
            }
        }
    }
    if (n > 1)
    {
        phi_n *= (n - 1);
        phi_n /= n;
    }

    return phi_n;
}


/// returns count of numbers ranged 1 to n that are not coprime with x
ll notPhi(ll n)
{
    vector<int> prime_factors;

    ll xx = x;

    //ll sq = sqrtl(xx + 100);

    for (int i = 0; i < prime.size() and prime[i] * prime[i] <= xx; i++)
    {
        if (xx % prime[i] == 0)
        {
            prime_factors.push_back(prime[i]);

            while (xx % prime[i] == 0)
            {
                xx /= prime[i];
            }
        }
    }
    if (xx > 1)
    {
        prime_factors.push_back(xx);
    }

    // cout << "pf : ";
    // for (auto pf : prime_factors)
    // {
    //     cout << pf << " ";
    // }
    // cout << endl;

    int sz = 11;
    sz = prime_factors.size();
    int mask_max = (1 << sz);

    ll res = 0;


    for (int mask = 1; mask < mask_max; mask++)
    {
        int cnt = 0;
        ll lcm = 1;

        for (int bit = 0; bit < sz; bit++)
        {
            if (isSet(mask, bit))
            {
                cnt++;
                lcm *= prime_factors[bit];
            }
        }
        if (cnt & 1)
        {
            // n / lcm numbers in range [1, n] are multiple of lcm
            // x is also multiple of lcm so they are not co-primes
            // using inclusion-exclusion we can count that
            res += (n / lcm);
        }
        else
        {
            res -= (n / lcm);
        }
    }

    //watch2(n, res);

    return res;

}


ll g(ll n)
{
    ll ans = 0;
    if (n >= x)
    {
        ans += phi(x) * (n / x);
    }

    //watch(ans);

    if (n % x)
    {
        ans += ((n % x) - notPhi(n % x));
    }

    //watch2(n, ans);

    return ans;
}


void solve_case()
{
    cin >> a >> b >> m;
    if (b < a) swap(a, b);

    x = b - a;

    //watch(x);
    cout << "Case " << tc << ": ";

    if (x == 0)
    {
        if (b != 1)
        {
            cout << 0 << endl;
        }
        else cout << 1 << endl;

        return;
    }

    //gcd(x, a + i) == 1

    ll res = (a + m) - notPhi(a + m);  /// g(n) : gcd(x, 1 to n) == 1
    //watch2(a + m, res);
    if (a != 1)
        res -= ((a - 1) - notPhi(a - 1));

    cout << res << endl;



    return;
}

int main()
{
    faster_io;
    linearSieve(mxn - 1);

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

