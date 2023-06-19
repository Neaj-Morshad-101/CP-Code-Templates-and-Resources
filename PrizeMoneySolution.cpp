#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	assert(t >= 1 and t <= 1000);
	while (t--)
	{
		int n;
		cin >> n;

		assert(n >= 1 and n <= 1000);

		if (n == 1)
		{
			cout << 3000 << endl;
		}
		else if (n == 2)
		{
			cout << 2000 << endl;
		}
		else if (n == 3)
		{
			cout << 1500 << endl;
		}
		else if (n == 4 or n == 5)
		{
			cout << 1000 << endl;
		}
		else if (n <= 10)
		{
			cout << 500 << endl;
		}
		else cout << "Only Snacks" << endl;

	}
}