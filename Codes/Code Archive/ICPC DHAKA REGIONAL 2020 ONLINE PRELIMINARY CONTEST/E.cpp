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
    cout << "Case " << tc << ": ";
    int n;
    cin >> n;
    int arr[n];

    int mx = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }


    vector<int> v;
    int idx = -1;

    while ((idx + 1 < n) and (arr[idx + 1] <= 0))
    {
        idx++;
    }

    int idx2 = n;

    while ((idx2 - 1) >= 0 and arr[idx2 - 1] <= 0)
    {
        idx2--;
    }

    if (idx2 <= idx)
    {
        cout << mx << " " << 0 << endl;
        return;
    }

    ll ans = 0;

    for (int i = idx + 1; i < idx2; i++)
    {
        v.push_back(arr[i]);
        if (arr[i] > 0) ans  += arr[i];
    }

    cout << ans << " ";


    int negs = 0;
    int  prev_neg = false;

    int sz = v.size();

    for (int i = 1; i < sz; i++)
    {
        int x = v[i];
        if (prev_neg)
        {
            if (x > 0)
            {
                prev_neg = false;
            }
        }
        else
        {
            //prev positive
            if (x < 0)
            {
                prev_neg = true;
                negs++;
            }
        }

    }

    cout << negs << endl;


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

