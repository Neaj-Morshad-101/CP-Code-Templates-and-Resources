//Good problem : https://www.codechef.com/viewsolution/73816202

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


#define MAX 5
ll MOD = 1e9 + 7;
ll MOD2 = MOD * MOD * 3;
inline ll bigMod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD; b >>= 1;
    }
    return res;
}
inline ll inv(ll n) {return bigMod(n, MOD - 2);}
inline ll Mul(ll a, ll b) {return (a * b) % MOD;}
inline ll Div(ll a, ll b) {return Mul(a, inv(b));}
/* 1 base row columun index */
struct Matrix {
    int row, col;
    ll m[MAX][MAX];
    Matrix() {memset(m, 0, sizeof(m));}
    void Set(int r, int c) {row = r; col = c;}
    Matrix(int r, int c) {memset(m, 0, sizeof(m)); Set(r, c);}
    void normalize() {
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                m[i][j] %= MOD;
                if (m[i][j] < 0) m[i][j] += MOD;
            }
        }
    }
};
Matrix Multiply(Matrix A, Matrix B) {
    Matrix ans(A.row, B.col);
    for (int i = 1; i <= A.row; i++) {
        for (int j = 1; j <= B.col; j++) {
            ans.m[i][j] = 0;
            ll sm = 0;
            for (int k = 1; k <= A.col; k++) {
                sm += (A.m[i][k] * B.m[k][j]);
                if (sm >= MOD2) sm -= MOD2;
            }
            ans.m[i][j] = sm % MOD;
        }
    }
    return ans;
}
Matrix Power(Matrix mat, ll p) {
    Matrix res(mat.row , mat.col);
    Matrix ans(mat.row , mat.col);
    int n = ans.row;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans.m[i][j] = 0;
            res.m[i][j] = mat.m[i][j];
        }
        ans.m[i][i] = 1;
    }
    while (p) {
        if (p & 1) ans = Multiply(ans, res);
        res = Multiply(res, res);
        p = p / 2;
    }
    return ans;
}

///g(n) = a^0 + a^1 + a^2 + a^3 + a^4 + a^5 + .... + a^n
///We will maintain the current last-term of the series and sum of the series in out maxtrix.
///For the first term (a^0 = 1), and sum is 1

///So the first matrix is F0
// | 1 |
// | 1 |

///Second term is a and sum is a + 1, So F1 is

// | a     |
// | a + 1 |

// So A matrix will be

// | a  0 |
// | a  1 |

// F1 = A * F0
// Fn = A^n * F0
// Fn[1][1] = n-th Term
// Fn[2][1] = g(n)

void solve_case()
{
    int a, n;
    cin >> a >> n;
    Matrix A(2, 2);

    A.m[1][1] = a;
    A.m[1][2] = 0;
    A.m[2][1] = a;
    A.m[2][2] = 1;

    Matrix An = Power(A, n);

    Matrix f0(2, 1);

    f0.m[1][1] = 1;
    f0.m[2][1] = 1;

    Matrix Gn = Multiply(An, f0);

    cout << "Case " << tc << ": ";

    cout << Gn.m[2][1] << endl;


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

