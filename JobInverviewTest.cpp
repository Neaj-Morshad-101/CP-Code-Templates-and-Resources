#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll my_rand(ll l, ll r) {
	return uniform_int_distribution<ll>(l, r) (rng);
}

int main()
{
	freopen("job.txt", "w", stdout);
	int t = my_rand(18, 18);
	cout << t << endl;
	//cout << endl;
	while (t--)
	{
		int n = my_rand(100000, 100000);

		cout << n << endl;


		int bad = my_rand(1, 4);


		for (int i = 1; i <= n; i++)
		{
			int x = my_rand(1, 3);
			cout << x << " ";

			bool vis[5] = {false};
			vis[bad] = true;

			//vis[4] = true;
			for (int j = 1; j <= x; j++)
			{
				int r = my_rand(1, 4);
				while (vis[r])
				{
					r = my_rand(1, 4);
				}

				vis[r] = true;
				if (r == 1) cout << "DSA" << " ";
				if (r == 2) cout << "OOP" << " ";
				if (r == 3) cout << "DBMS" << " ";
				if (r == 4) cout << "CN" << " ";
			}
			cout << endl;
		}
		//cout << endl;
	}
}