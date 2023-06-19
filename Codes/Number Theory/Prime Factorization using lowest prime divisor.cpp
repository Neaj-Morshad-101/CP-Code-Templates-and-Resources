// Created by Neaj_Morshad_101
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

///define constant
const ll mxn = 1e7 + 100;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........

int tc;

int lp[mxn];
vector<int> pr; // primes

void linearSieve()
{
    const int N = mxn - 1;
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }

}


vector<pair<int, int>> primeFactorize(int num)
{
    vector<pair<int, int>> pf;

    while (num > 1)
    {
        int c = 0;
        int p = lp[num];
        while (num % p == 0)
        {
            num /= p;
            c++;
        }
        pf.push_back({p, c});
    }

    return pf;
}



void solve_case()
{
    int n;
    cin >> n;
    watch(n);
    vector<pair<int, int>> pf = primeFactorize(n);

    for (auto [p, c] : pf)
    {
        cout << p << " " << c << endl;
    }




    return;
}

int main()
{
    faster_io;
    linearSieve();


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

