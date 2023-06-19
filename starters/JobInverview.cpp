#include<bits/stdc++.h>
using namespace std;

int getValue(string s)
{
	if (s == "DSA") return 1;
	if (s == "OOP") return 2;
	if (s == "DBMS") return 4;
	if (s == "CN") return 8;

	cout << s << " ";

	cout << "Invalid String" << endl;
	return 0;
}

int main()
{
	int t;
	cin >> t;
	assert(t >= 1 and t <= 100);

	while (t--)
	{
		int n;
		cin >> n;
		assert(n >= 1 and n <= 1e5);
		//cout << "n : " << n << endl;

		bool mask[16] = {false};

		map<int, int> mp;

		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			//cout << "x : " << x << endl;
			assert(x >= 1 and x <= 4);
			int msk_val = 0;
			for (int j = 1; j <= x; j++)
			{
				string s;
				cin >> s;
				//cout << s << endl;
				msk_val += getValue(s);
			}
			//cout << i << " : " << msk_val << endl;

			mask[msk_val] = true;
			if (!mp.count(msk_val))
			{
				mp[msk_val] = i;
			}
		}

		if (mask[15] == true)
		{
			cout << 1 << endl;
			cout << mp[15] << endl;

			continue;
		}


		///try 2^14 comnbinations

		vector<int> ans_v;
		int ans = INT_MAX;

		for (int m = 1; m < (1 << 14); m++)
		{
			//if (m != 576) continue;
			//cout << "m : " << m << endl;
			int cur_mask = 0;
			int cur_ans = 0;
			vector<int> cur_v;
			for (int j = 0; j < 14; j++)
			{
				if ((m & (1 << j)) > 0)
				{
					//cout << "j + 1 : " << j + 1 << endl;
					cur_ans++;
					cur_v.push_back(mp[j + 1]);
					if (mask[j + 1])
						cur_mask |= (j + 1);
				}
			}

			// cout << "cur_v : " << endl;
			// for (int val : cur_v)
			// {
			// 	cout << val << " ";
			// }
			// cout << endl;

			if (cur_mask == 15 and cur_ans <= ans)
			{
				sort(cur_v.begin(), cur_v.end());

				//cout << "cur_ans : " << cur_ans << " " << "ans : " << ans << endl;
				if (cur_ans < ans)
				{
					ans_v = cur_v;
					ans = cur_ans;
				}
				else
				{
					if (cur_v < ans_v)
					{
						ans_v = cur_v;
					}
				}
			}

		}

		//cout << "ans : " << ans << endl;

		if (ans == INT_MAX)
		{
			cout << "Make more friends, Neaj." << endl;
		}
		else
		{
			cout << ans << endl;
			for (int id : ans_v)
			{
				cout << id << " ";
			}
			cout << endl;
		}

	}
}