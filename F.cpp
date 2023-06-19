// Created by Neaj_Morshad_101
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

///constants
const ll mxn = 200200;
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




void solve_case()
{
    int rem = -5 % 4;
    if (rem < 0)
        rem += 4;
    cout << rem << endl;


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

