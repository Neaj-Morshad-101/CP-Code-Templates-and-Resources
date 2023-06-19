//https://codeforces.com/contest/1744/problem/E2
// Created by Neaj_Morshad_101
#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef long double ld;

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

#define pii pair<ll,int>

ll Mul(ll a, ll b, ll Mod) {
	ll Ans = 0;
	while (b) {
		if (b & 1) {Ans += a; if (Ans >= Mod) Ans -= Mod;}
		a += a; if (a >= Mod) a -= Mod;
		b >>= 1;
	}
	return Ans;
}

ll bigMod(ll n, ll r, ll Mod) {
	if (r == 0) return 1LL;
	ll ret = bigMod(n, r / 2, Mod);
	ret = Mul(ret, ret, Mod);
	if (r % 2 == 1) ret = Mul(ret, n, Mod);
	return ret;
}

//Miller-Rabin
bool witness(ll wit, ll n) {
	if (wit >= n) return false;

	int s = 0; ll t = n - 1;
	while (t % 2 == 0) s++, t /= 2;

	wit = bigMod(wit, t, n);
	if (wit == 1 || wit == n - 1) return false;

	for (int i = 1; i < s; i++) {
		wit = Mul(wit, wit, n);
		if (wit == 1) return true;
		if (wit == n - 1) return false;
	}
	return true;
}

//Is n prime?
bool miller(ll n) {
	if (n == 2) return true;
	if (n % 2 == 0 || n < 2) return false;
	if (witness(2, n) || witness(7, n) || witness(61, n)) return false;
	return true;
}

// Pollard's Rho
// a must not equal 0 or -2.
// returns a divisor, a proper one when succeeded, equal to n if failed
// in case of failure, change a
ll rho(ll n, ll a) {
	auto f = [&](ll x) {return (Mul(x, x, n) + a) % n; };
	ll x = 2, y = 2;
	for (int i = 1;; i++) {
		x = f(x); y = f(f(y));
		ll d = __gcd(n, abs(x - y));
		if (d != 1) return d;
	}
	return n;
}

ll get_factor(ll n) {
	if (n % 2 == 0) return 2;
	if (n % 3 == 0) return 3;
	if (n % 5 == 0) return 5;
	while (true) {
		ll a = 2 + rand() % 100;
		ll d = rho(n, a);
		if (d != n) return d;
	}
	return n;
}

void factorize(ll n, vector<ll> &x) {
	if (n == 1) return;
	else if (miller(n)) x.push_back(n);
	else {
		ll d = get_factor(n);
		factorize(d, x);
		factorize(n / d, x);
	}
}

vector<ll>factorize(ll n) {vector<ll>x; factorize(n, x); return x;}

vector<pii>Factors;
vector<ll>Divisors;
void findDiv(int pos, ll val) {
	if (pos < 0) {Divisors.push_back(val); return;}
	ll Now = 1;
	for (int i = 0; i <= Factors[pos].second; i++) {
		findDiv(pos - 1, val * Now);
		Now = Now * Factors[pos].first;
	}
}

void findAllDiv(ll n) {
	if (n == 1) {
		Divisors.push_back(1);
		return;
	}
	vector<ll>now = factorize(n);
	sort(now.begin(), now.end());

	Factors.clear();
	Divisors.clear();

	int Count = 1;
	for (int i = 1; i < now.size(); i++) {
		if (now[i] == now[i - 1]) Count++;
		else {Factors.push_back({now[i - 1], Count}); Count = 1;}
	}
	Factors.push_back({now.back(), Count});
	findDiv(Factors.size() - 1, 1);
}

void solve_case()
{

	//code started
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll ab = a * b;
	//cout << ab << endl;

	findAllDiv(ab);

	// for (auto x : Divisors)
	// {
	//     cout << x << " ";
	// }
	// cout << endl;

	pair<ll, ll> p = { -1, -1};



	for (auto x : Divisors)
	{
		ll g = __gcd(x, ab);
		ll y = ab / g;
		ll ansy = -1;

		ll ny = (d / y) * y;
		if (ny > b)
		{
			ansy = ny;
		}


		ll ansx = -1;
		ll nx = (c / x) * x;
		if (nx > a)
		{
			ansx = nx;
		}

		if (ansy != -1 and ansx != -1)
		{
			p = {ansx, ansy};
			break;
		}
	}

	cout << p.first << " " << p.second << endl;


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


