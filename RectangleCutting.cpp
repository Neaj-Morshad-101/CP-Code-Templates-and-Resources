#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl

#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;

	while (t--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		// watch2(a, b);
		// watch2(c, d);

		int C; cin >> C;
		// watch(C);

		multiset<int> difs_x, difs_y;
		ordered_set points_x, points_y;

		difs_x.insert(c - a);
		difs_y.insert(d - b);

		points_x.insert(a);
		points_x.insert(c);

		// cout << "points_x : ";

		// for (auto val : points_x)
		// {
		// 	cout << val << " ";
		// }
		// cout << endl;

		points_y.insert(b);
		points_y.insert(d);


		while (C--)
		{
			char ch;
			cin >> ch;

			if (ch == 'x')
			{
				cin >> ch;

				int p; cin >> p;

				// watch(p);

				auto it = points_x.upper_bound(p);
				int next_p = (*it);
				it--;
				int prev_p = (*it);


				// watch2(prev_p, next_p);

				int prev_dif = next_p - prev_p;

				// watch(prev_dif);



				difs_x.erase(difs_x.find(prev_dif));

				int new_dif1 = next_p - p;
				int new_dif2 = p - prev_p;

				difs_x.insert(new_dif1);
				difs_x.insert(new_dif2);
				points_x.insert(p);

				auto ms_y_it = difs_y.end();;
				ms_y_it--;

				int mx_dif_y = (*ms_y_it);

				ll ans = mx_dif_y * 1ll *  max(new_dif1, new_dif2);

				cout << ans << endl;

			}
			else
			{
				cin >> ch;

				int q; cin >> q;

				// watch(p);

				auto it = points_y.upper_bound(q);
				int next_q = (*it);
				it--;
				int prev_q = (*it);



				int prev_dif = next_q - prev_q;

				// watch(prev_dif);



				difs_y.erase(difs_y.find(prev_dif));

				int new_dif1 = next_q - q;
				int new_dif2 = q - prev_q;

				difs_y.insert(new_dif1);
				difs_y.insert(new_dif2);
				points_y.insert(q);

				auto ms_x_it = difs_x.end();;
				ms_x_it--;

				int mx_dif_x = (*ms_x_it);

				ll ans = mx_dif_x * 1ll *  max(new_dif1, new_dif2);

				cout << ans << endl;
			}
		}

	}
}