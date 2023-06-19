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

ld distance(pair<int, int> a, pair<int, int> b)
{
	ld x1 = a.first, x2 = b.first;
	ld y1 = a.second, y2 = b.second;

	ld dx = x2 - x1;
	ld dy = y2 - y1;

	dx = dx * dx;
	dy = dy * dy;

	return sqrtl(dx + dy);
}


void solve_case()
{
	int n;
	cin >> n;

	// vector<int> vx[1005];
	// vector<int> vy[1005];

	pair<int, int> arr[n];

	// int minx = 1e5, maxx = -1;
	// int miny = 1e5, maxy = -1;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[i].first = x;
		arr[i].second = y;

		// minx = min(minx, x);
		// maxx = max(maxx, x);

		// miny = min(miny, y);
		// maxy = max(maxy, y);

		// vx[x].push_back(y);
		// vy[y].push_back(x);
	}

	// pair<int, int> a, b, c, d;

	// a.first = minx;
	// b.first = minx;

	// c.first = maxx;
	// d.first = maxx;

	// sort(vx[minx].begin(), vx[minx].end());
	// sort(vx[maxx].begin(), vx[maxx].end());

	// a.second = vx[minx][0];
	// b.second = vx[minx][(int)vx[minx].size() - 1];
	// c.second = vx[maxx][0];
	// d.second = vx[maxx][(int)vx[maxx].size() - 1];


	ld max_dis = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			max_dis = max(max_dis, distance(arr[i], arr[j]));
		}
	}

	// max_dis = max(max_dis, distance(a, c));
	// max_dis = max(max_dis, distance(a, d));
	// max_dis = max(max_dis, distance(b, c));
	// max_dis = max(max_dis, distance(b, d));

	// // cout << sqrtl(200) / 2 << endl;


	// swap(vx, vy);
	// swap(minx, miny);
	// swap(maxx, maxy);


	// a.first = minx;
	// b.first = minx;

	// c.first = maxx;
	// d.first = maxx;

	// sort(vx[minx].begin(), vx[minx].end());
	// sort(vx[maxx].begin(), vx[maxx].end());

	// a.second = vx[minx][0];
	// b.second = vx[minx][(int)vx[minx].size() - 1];
	// c.second = vx[maxx][0];
	// d.second = vx[maxx][(int)vx[maxx].size() - 1];


	// max_dis = max(max_dis, distance(a, c));
	// max_dis = max(max_dis, distance(a, d));
	// max_dis = max(max_dis, distance(b, c));
	// max_dis = max(max_dis, distance(b, d));


	cout << fixed << setprecision(16) << max_dis / 2.0 << endl;


	return;
}

int main()
{
	faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


	int total_test = 1;
	//cin >> total_test;
	for (int test_case = 1; test_case <= total_test; test_case++)
	{
		tc = test_case;
		solve_case();
	}
///  KeyPoint


///  Corner Cases




	return 0;
}

