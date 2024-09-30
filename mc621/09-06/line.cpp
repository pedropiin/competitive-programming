#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Extended GCD implementation taken from www.cp-algorithms.com
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;
	ll d = extended_gcd(b, (a % b), x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);;
	return d;
}

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;
	ll gcd, x, y;
	gcd = extended_gcd(a, b, x, y);

	if ((-c) % gcd == 0) {
		cout << (x * (-c) / gcd) << " " << (y * (-c) / gcd) << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}
