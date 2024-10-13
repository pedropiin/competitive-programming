#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007

void fib(ll &n, ll &x, ll &y) {
	if (n == 0) {
		x = 0;
		y = 1;
	} else {
		ll div = n / 2;
		fib(div, x, y); // calculating f(2k) and f(2k + 1)

		ll a = x, b = y;

		x = (2 * b) - a;
		if (x < 0) {
			x += MOD;
		}
		x = (a * x) % MOD;

		y = ((a * a) % MOD) + ((b * b) % MOD);

		if (n % 2 != 0) {
			ll tmp = x;
			x = y;
			y += tmp;
		}
	
		x = x % MOD;
		y = y % MOD;
	}
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n;
	
	ll x, y;
	fib(n, x, y);

	cout << x << endl;



	return 0;
}
