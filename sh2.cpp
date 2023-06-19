#include<bits/stdc++.h>
//#define int long long int
#define pb push_back
#define se second
#define fi first
using namespace std;

int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int mod = 1000000007;
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree <
    pair<int ,int>,
    nuint_type,
    less<pair<int ,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;
*/

// To find GCD of a and b
#define int long long
int gcd(int a, int b);

// To compute x raised to power y under modulo M
int power(int x, unsigned int y, unsigned int M);

// Function to find modular inverse of a under modulo M
// Assumption: M is prime
void modInverse(int A, int M)
{
    int g = gcd(A, M);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else {
        // If a and m are relatively prime, then modulo
        // inverse is a^(m-2) mode m
        cout << "Modular multiplicative inverse is "
             << power(A, M - 2, M);
    }
}

// To compute x^y under modulo m
int power(int x, unsigned int y, unsigned int M)
{
    if (y == 0)
        return 1;

    int p = power(x, y / 2, M) % M;
    p = (p * p) % M;

    return (y % 2 == 0) ? p : (x * p) % M;
}

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void solve(int tc)
{
    int n, i, j, sum = 0;

    cin >> n;

    j = n - 1;

    int ans = (j * (j + 1)) % mod;

    ans = (ans * (2 * j + 1) % mod) % mod;

    ans = (2LL * ans) % mod;

    int y = modInverse(6LL, mod) % mod;

    ans = (ans * y) % mod;

    y = modInverse(2LL, mod) % mod;

    int x = ((j * (j + 1))) % mod;

    ans = (ans + (x * y) % mod) % mod;

    ans = (ans + (n * n) % mod) % mod;

    ans = (2022 * ans) % mod;

    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //pre();

    int tc = 1;
    cin >> tc;

    for (int tt = 1; tt <= tc; tt++)
    {
        solve(tt);
    }
    return 0;
}