// Created by Neaj_Morshad_101
#include <sys/resource.h>
//include it at the beggining of the program
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

///define constant
const ll mxn = 1000006;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........

int tc;


int arr[mxn + 1];
int p[mxn + 1][4];

#define Left (node*2)
#define Right (node*2+1)
#define Mid ((b+e)/2)

// struct NODE
// {
//     NODE(int a, int l, int r)
//     {
//         this->a = a;
//         this->l = l;
//         this->r = r;
//     }
//     NODE () {}
//     int a, l, r;

// } tree[4*mxn];

// NODE dummy = {0, 0, 0};
// NODE node = {2, 45, 9};

int n;

ll tree[4 * mxn][4]; // for N size arary segment tree contains 2N-1 nodes if N is a power of 2. so max size will be 4*N (we need to make N a power of 2)
ll lazy[4 * mxn][4];

//Merge complexity will be multiplied by each of the complexity of build, update and query
//Merging Two Nodes Data

//O(N) because number of nodes in the segment tree is 2*N.
void build(int node, int b, int e, int tp) //current node and node's range (begin to end)
{
    lazy[node][tp] = 0;  /// *** may change depending on the problem...
    if (b == e)
    {
        tree[node][tp] = p[b][tp];
        return;
    }

    build(Left, b, Mid, tp);
    build(Right, Mid + 1, e, tp);

    tree[node][tp] = tree[Left][tp] + tree[Right][tp];
}

//O(4*log(N))     at most four nodes are visited in the segment tree.

//O(1)
void lazyPropagation(int node, int b, int e, int tp) // current node and node's range (b to e)
{
    if (lazy[node][tp])
    {
        tree[node][tp] += (e - b + 1) * lazy[node][tp]; /// *** may change depending on the problem.. //Adding extra sum // for max query  New Max = Max + lazy[node]
        if (b != e)
        {
            lazy[Left][tp] += lazy[node][tp];
            lazy[Right][tp] += lazy[node][tp];
        }
        lazy[node][tp] = 0;
    }
}

//O(4*log(N))     at most four nodes are visited in the segment tree.
void updateRange(int node, int b, int e, int i, int j, int val, int tp)   // current node and node's range (b to e) and update on index i to j with value val ( arr[i] = arr[i+1] = .. = arr[j]  will be (+= val ) )
{
    lazyPropagation(node, b, e, tp);
    if (b > e) return; // invalid update query like -> updateRange(10, 5) here b > e
    else if (b > j || e < i) return;
    if (b >= i && e <= j)
    {
        lazy[node][tp] += val; /// *** may change depending on the problem...
        lazyPropagation(node, b, e, tp);
        return;
    }
    updateRange(Left, b, Mid, i, j, val, tp);
    updateRange(Right, Mid + 1, e, i, j, val, tp);
    tree[node][tp] = tree[Left][tp] + tree[Right][tp];
}

//O(4*log(N))     at most four nodes are visited in the segment tree.
ll queryRange(int node, int b, int e, int i, int j, int tp) //current node and node's range (b to e) and query range (i to j)
{
    if (b > e) return 0; /// *** may change depending on the problem...
    else if (b > j || e < i) return 0; /// *** may change depending on the problem...
    lazyPropagation(node, b, e, tp);
    if (b >= i && e <= j) return tree[node][tp];
    ll p1 = queryRange(Left, b, Mid, i, j, tp);
    ll p2 = queryRange(Right, Mid + 1, e, i, j, tp);
    return  p1 + p2;               //p1 + p2; sum query
}




void solve_case()
{
    int n, m;
    cin >> n >> m;

    p[0][1] = 0;
    p[0][2] = 0;
    p[0][3] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        for (int j = 1; j <= 3; j++)
        {
            p[i][j] = p[i - 1][j];
        }
        p[i][arr[i]]++;
    }

    for (int i = 1; i <= 3; i++)
    {
        build(1, 1, n, i);
    }

    ll ans = 0;

    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int chilo = -1;
        for (int tp = 1; tp <= 3; tp++)
        {
            if (queryRange(1, 1, n, x, x, tp) == 1)
            {
                chilo = tp;
            }
        }

        updateRange(1, 1, n, x, n, -1, chilo);
        updateRange(1, 1, n, x, n, +1, y);

        ll left = z;
        ll right = n - z;

        ll l_cnt[4] = {0};
        ll r_cnt[4] = {0};

        ll total_sum = 0;
        ll left_sum = 0;

        for (int i = 1; i <= 3; i++)
        {
            l_cnt[i] = queryRange(1, 1, n, 1, z, i);
            r_cnt[i] = queryRange(1, 1, n, z + 1, n, i);

            total_sum += (i * (l_cnt[i] + r_cnt[i]));
            left_sum += (i * (l_cnt[i]));
        }

        ll right_sum = total_sum - left_sum;

        if (total_sum & 1)
        {
            ans--;
            continue;
        }

        if (left_sum > right_sum)
        {
            ll q = 0;
            ll barti = left_sum - right_sum;
            ll parbo2 = barti / 2;

            ll shift = min(l_cnt[1], r_cnt[3]);
            shift = min(shift, parbo2);

            l_cnt[1] -= shift;
            r_cnt[3] -= shift;
            left_sum -= 2 * shift;
            right_sum += 2 * shift;

            q += shift;

            barti = left_sum - right_sum;
            ll parbo1 = barti;

            ll s1 = min(l_cnt[1], r_cnt[2]);
            ll s2 = min(l_cnt[2], r_cnt[3]);
            shift = s1 + s2;

            if (shift != parbo1)
            {
                continue;
            }
            shift = min(shift, parbo1);

            l_cnt[1] -= shift;
            r_cnt[2] -= shift;
            r_cnt[2] -= shift;
            r_cnt[3] -= shift;

            left_sum -= shift;
            right_sum += shift;

            q += shift;

            ans += q;
        }

        else if (left_sum < right_sum)
        {
            swap(left_sum, right_sum);
            for (int i = 1; i <= 3; i++)
            {
                swap(l_cnt[i], r_cnt[i]);
            }
            ll q = 0;
            ll barti = left_sum - right_sum;
            ll parbo2 = barti / 2;

            ll shift = min(l_cnt[1], r_cnt[3]);
            shift = min(shift, parbo2);

            l_cnt[1] -= shift;
            r_cnt[3] -= shift;
            left_sum -= 2 * shift;
            right_sum += 2 * shift;

            q += shift;

            barti = left_sum - right_sum;
            ll parbo1 = barti;

            ll s1 = min(l_cnt[1], r_cnt[2]);
            ll s2 = min(l_cnt[2], r_cnt[3]);
            shift = s1 + s2;

            if (shift != parbo1)
            {
                continue;
            }
            shift = min(shift, parbo1);

            l_cnt[1] -= shift;
            r_cnt[2] -= shift;
            r_cnt[2] -= shift;
            r_cnt[3] -= shift;

            left_sum -= shift;
            right_sum += shift;

            q += shift;

            ans += q;

        }




    }

    cout << ans << endl;


    return;
}

int main()
{
    //maybe it is only for linux
    //include these lines at the beggining of the main function
    struct rlimit rl;
    const rlim_t kStackSize = 512L * 1024L * 1024L;
    assert(!getrlimit(RLIMIT_STACK, &rl));
    rl.rlim_cur = kStackSize;
    assert(!setrlimit(RLIMIT_STACK, &rl));
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

