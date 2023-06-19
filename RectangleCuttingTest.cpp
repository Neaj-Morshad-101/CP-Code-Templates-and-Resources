#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll my_rand(ll l, ll r) {
	return uniform_int_distribution<ll>(l, r) (rng);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = my_rand(1, 10);
	assert(t >= 1 and t <= 10);

	cout << t << endl;

	while (t--)
	{
		int a, b, c, d, C;
		a = my_rand(0, 5);
		b = my_rand(0, 5);
		c = my_rand(0, 5);
		d = my_rand(0, 5);
		C = my_rand(1, 5);
		// cout << a << " " << b << " " << c << " " << d << endl;
		// cout << C << endl;

		while (a >= c or b >= d or (c - a - 1) + (d - b - 1) < C)
		{
			a = my_rand(0, 5);
			b = my_rand(0, 5);
			c = my_rand(0, 5);
			d = my_rand(0, 5);
			C = my_rand(1, 5);
		}

		cout << a << " " << b << " " << c << " " << d << endl;
		cout << C << endl;

		// cout << "inpt " << endl;
		map<int, bool> mpx, mpy;

		while (C--)
		{
			// cout << "C : " << endl;
			int x_line = my_rand(0, 1);
			int x_baki = c - a - 1;
			int y_baki = d - b - 1;
			if (x_line == 1 and x_baki == 0)
			{
				x_line = 0;
			}
			if (x_line == 0 and y_baki == 0)
			{
				x_line = 1;
			}


			if (x_line == 1)
			{
				assert(x_baki > 0);
				int p = my_rand(a + 1, c - 1);
				while (mpx[p] == true)
				{
					p = my_rand(a + 1, c - 1);
				}

				mpx[p] = true;
				cout << "x = " << p << endl;
			}
			else
			{
				assert(y_baki > 0);
				int q =  my_rand(b + 1, d - 1);
				while (mpy[q] == true)
				{
					q = my_rand(b + 1, d - 1);
				}
				mpy[q] = true;
				cout << "y = " << q << endl;
			}
		}
	}

	return 0;
}