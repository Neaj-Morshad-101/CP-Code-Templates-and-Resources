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

int n;
vector<int> v;

int lp[mxn];
vector<int> pr; // primes

unordered_set<int> mulp[mxn];
unordered_set<int> achep;
bool vis[mxn];
vector<int> pfac[mxn];

void linearSieve()
{
	const int N = mxn - 1;
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
			lp[i * pr[j]] = pr[j];
	}

}

///using lp[] array : lowest prime divisor
vector<int> primeFactorize(int num)
{
	vector<int> pf;
	while (num > 1)
	{
		int p = lp[num];
		while (num % p == 0)
		{
			num /= p;
		}
		pf.push_back(p);
	}
	return pf;
}

int components = 0;
int component_size[mxn];
int cnt[mxn];

void bfs(int x)
{
	//watch2(x, components);
	queue<int> Q;
	Q.push(x);
	component_size[x] = 1;

	while (!Q.empty())
	{
		int num = Q.front();
		Q.pop();

		//watch(num);

		vector<int> bad_prime;

		for (auto prime : achep)
		{
			if (num % prime == 0)
			{
				if (mulp[prime].find(num) != mulp[prime].end())
				{
					mulp[prime].erase(mulp[prime].find(num));
					if (mulp[prime].size() == 0)
					{
						bad_prime.push_back(prime);
					}
				}


			}
			else
			{
				for (auto vals : mulp[prime])
				{
					if (vis[vals]) continue;
					bool ok = true;
					for (int i = 0; i < pfac[num].size(); i++)
					{
						if ((vals % pfac[num][i]) == 0)
						{
							ok = false;
							break;
						}
					}
					if (ok)
					{
						vis[vals] = true;
						component_size[x]++;
						Q.push(vals);
					}
				}
			}
		}

		for (auto prime : bad_prime)
		{
			if (achep.find(prime) != achep.end())
				achep.erase(achep.find(prime));
		}

		// for (auto x : achep)
		// {
		// 	cout << "prime set " << x << ": ";
		// 	for (auto val : mulp[x])
		// 	{
		// 		cout << val << " ";
		// 	}
		// 	cout << endl;
		// }
	}

}


int main()
{
	linearSieve();

	scanf("%d", &n);
	v.resize(n);
	bool one = false;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
		cnt[v[i]]++;
		if (v[i] == 1)
		{
			one = true;
		}
	}
	if (one)
	{
		printf("1\n");
		return 0;
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	// cout << "vec : ";

	// for (auto x : v) cout << x << " "; cout << endl;

	for (int i = 0; i < v.size(); i++)
	{
		pfac[v[i]] = primeFactorize(v[i]);

		for (auto p : pfac[v[i]])
		{
			achep.insert(p);
			mulp[p].insert(v[i]);
		}
	}

	// cout << "achep : ";

	// for (auto x : achep) cout << x << " "; cout << endl;

	// for (auto x : achep)
	// {
	// 	cout << "prime set " << x << ": ";
	// 	for (auto val : mulp[x])
	// 	{
	// 		cout << val << " ";
	// 	}
	// 	cout << endl;
	// }

	for (int i = 0; i < v.size(); i++)
	{
		if (!vis[v[i]])
		{
			vis[v[i]] = true;
			bfs(v[i]);
			if (component_size[v[i]] == 1)
			{
				components += cnt[v[i]];
			}
			else components++;

		}
	}
	printf("%d\n", components);


	return 0;
}

