// TC: O(n*s/64),
// bit[s] = true is s can be obtained by any subsequence picked form the array..

//bitset operation takes O(n / 64);
#include<bits/stdc++.h>
using namespace std;

#define mx 4000005
#define ll long long
#define mod 1000000007 //998244353


int n, m, ii, k;
bitset<mx>bt;

void solve()
{
    scanf("%d", &n);
    int total = 0;
    bt[0] = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        total += x;
        bt |= (bt << x);
    }

    int re = (total + 1) / 2;
    while (1) {
        if (bt[re] == true) {
            printf("%d\n", re );
            return;
        }
        re++;
    }

}

int main()
{
    int t = 1;
    // scanf("%d",&t);
    while (t--)solve();
    return 0;
}