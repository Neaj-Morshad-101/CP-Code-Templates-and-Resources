// Created by Neaj_Morshad_101
//ICPC Preli 2022 H
//
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

#define Left (node*2)
#define Right (node*2+1)
#define Mid ((b+e)/2)

int tc;
string s[2];
int q;


vector<int> tree[4 * mxn][2];
vector<int> lazy[4 * mxn][2];

//Merge complexity will be multiplied by each of the complexity of build, update and query
//Merging Two Nodes Data
vector<int> Merge(vector<int> a, vector<int> b)
{
    vector<int> res(26);
    for (int i = 0; i < 26; i++)
    {
        res[i] = a[i] + b[i];
    }
    return res; /// *** may change depending on the problem...
}

//O(N) because number of nodes in the segment tree is 2*N.
void build(int node, int b, int e, int tp) //current node and node's range (begin to end)
{
    //lazy[node] = 0;  /// *** may change depending on the problem...
    lazy[node][tp].resize(26);
    tree[node][tp].resize(26);
    lazy[node][tp][0] = -1;
    if (b == e)
    {
        int id = s[tp][b - 1] - 'a';

        for (int i = 0; i < 26; i++)
        {
            tree[node][tp][i] = (i == id);
        }

        //tree[node] = arr[b];
        return;
    }

    build(Left, b, Mid, tp);
    build(Right, Mid + 1, e, tp);

    tree[node][tp] = Merge(tree[Left][tp], tree[Right][tp]);
}


//O(1)
void lazyPropagation(int node, int b, int e, int tp) // current node and node's range (b to e)
{
    if (lazy[node][tp][0] != -1)
    {
        for (int i = 0; i < 26; i++)
        {

            tree[node][tp][i] = lazy[node][tp][i] * (e - b + 1);

        }
        //tree[node] += (e - b + 1) * lazy[node]; /// *** may change depending on the problem.. //Adding extra sum // for max query  New Max = Max + lazy[node]
        if (b != e)
        {
            lazy[Left][tp] = lazy[node][tp];
            lazy[Right][tp] = lazy[node][tp];
        }
        lazy[node][tp][0] = -1;
    }
}

//O(4*log(N))     at most four nodes are visited in the segment tree.
void updateRange(int node, int b, int e, int tp, int i, int j, int val)   // current node and node's range (b to e) and update on index i to j with value val ( arr[i] = arr[i+1] = .. = arr[j]  will be (+= val ) )
{
    lazyPropagation(node, b, e, tp);
    if (b > e) return; // invalid update query like -> updateRange(10, 5) here b > e
    else if (b > j || e < i) return;
    if (b >= i && e <= j)
    {
        for (int i = 0; i < 26; i++)
        {
            if (i == val)
            {
                lazy[node][tp][i] = 1;
            }
            else
            {
                lazy[node][tp][i] = 0;
            }
        }
        //lazy[node] += val; /// *** may change depending on the problem...
        lazyPropagation(node, b, e, tp);
        return;
    }
    updateRange(Left, b, Mid, tp, i, j, val);
    updateRange(Right, Mid + 1, e, tp, i, j, val);
    tree[node][tp] = Merge(tree[Left][tp], tree[Right][tp]);
}

//O(4*log(N))     at most four nodes are visited in the segment tree.
vector<int> queryRange(int node, int b, int e, int tp, int i, int j) //current node and node's range (b to e) and query range (i to j)
{
    vector<int> v(26, 0);
    if (b > e)
    {
        return v; /// *** may change depending on the problem...
    }
    else if (b > j || e < i) return v; /// *** may change depending on the problem...
    lazyPropagation(node, b, e, tp);
    if (b >= i && e <= j) return tree[node][tp];

    vector<int> p1(26);
    vector<int> p2(26);
    p1 = queryRange(Left, b, Mid, tp, i, j);
    p2 = queryRange(Right, Mid + 1, e, tp, i, j);

    vector<int> ans(26);
    ans =  Merge(p1, p2);
    return ans;                    //p1 + p2; sum query
}


void solve_case()
{
    cin >> s[0] >> s[1];

    build(1, 1, s[0].size(), 0);
    build(1, 1, s[1].size(), 1);


    cin >> q;

    // vector<int> v1b = queryRange(1, 1, s[0].size(), 0, 1, s[0].size());
    // vector<int> v2b = queryRange(1, 1, s[1].size(), 1, 1, s[1].size());

    // for (int i = 0; i < 26; i++)
    // {
    //     watch2(v1b[i], v2b[i]);
    // }
    // cout << endl << endl;

    while (q--)
    {
        int type;
        cin >> type;

        int L1, R1, L2, R2;
        cin >> L1 >> R1;

        char ch;


        if (type <= 2)
        {
            cin >> ch;
            updateRange(1, 1, s[type - 1].size(), type - 1, L1, R1, (ch - 'a'));

            // vector<int> v1u = queryRange(1, 1, s[0].size(), 0, 2, 2);
            // vector<int> v2u = queryRange(1, 1, s[1].size(), 1, 1, 1);

            // for (int i = 0; i < 26; i++)
            // {
            //     watch2(v1u[i], v2u[i]);
            // }
            // cout << endl << endl;

        }
        else
        {
            cin >> L2 >> R2;

            /*            watch2(L1, R1);
                        watch2(L2, R2);
            */
            vector<int> v1q = queryRange(1, 1, s[0].size(), 0, L1, R1);
            vector<int> v2q = queryRange(1, 1, s[1].size(), 1, L2, R2);


            ll bad = 0;
            ll total = 0;
            ll n = 0, m = 0;

            for (int i = 0; i < 26; i++)
            {
                bad += (v1q[i] * 1ll * v2q[i]);
                //watch2(v1q[i], v2q[i]);
                n += v1q[i];
                m += v2q[i];
            }
            //cout << endl << endl;

            total = (n + 1) * (m + 1);

            //watch2(total, bad);


            total -= bad;

            cout << total << endl;
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

