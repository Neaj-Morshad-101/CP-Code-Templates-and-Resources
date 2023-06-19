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

// Logic :

// A2 = (p^2 / q^2) A1
// B2 = (p / q) B1

// When we multiply ID things,

// L2 = n * L1

// for 2D things

// A2 = n^2 * A1

// for 3D things

// V2 = n^3 = V1

int tc;

ll i1, i2, p, q;

void solve_case()
{
    ll X = p * p * (i1 - 1) - (i2 * q * q) + (q * q);
    ll Y = p * (q - p);

    ld XX = (ld)X;
    XX /= (ld)Y;

    XX = (i1 + XX - 1) * 2;

    ll ans = round(XX);

    cout << ans << endl;

    return;
}

int main()
{
    faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    while (true)
    {
        cin >> i1 >> i2;
        cin >> p;
        char ch;
        cin >> ch;
        cin >> q;

        //cout << p << " " << q << endl;
        if (p == 0 and q == 0)
        {
            break;
        }
        solve_case();
    }
///  KeyPoint


///  Corner Cases




    return 0;
}

