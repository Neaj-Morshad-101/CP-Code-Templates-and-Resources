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

int tc;




void solve_case()
{
    set<int> st;

    for (int n = 3; n <= 50000; n += 2)
    {
        // int n;
        // cin >> n;

        ll lcm = n - 1, aa = 1, bb = n - 1;
        for (ll a = 2; a <= n / 2; a++)
        {
            ll b = n - a;

            ll new_lcm = (a * b) / (__gcd(a, b));

            if (new_lcm < lcm)
            {
                lcm = new_lcm;
                aa = a;
                bb = b;
            }
        }

        if (lcm == n - 1) continue;

        if (aa > bb) swap(aa, bb);

        //cout << aa << " " << bb << endl;

        if ((n % aa) or (bb % aa))
        {
            cout << "think man" << endl;
        }
        else if (st.find(bb / aa) == st.end())
        {
            //cout << n << " = " << aa << " + " << bb << endl;
            //if (aa * aa != n)
            cout << "n/aa" << " = " << n / aa << " aa*aa = " << aa * aa << endl;
            st.insert(bb / aa);
        }
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

