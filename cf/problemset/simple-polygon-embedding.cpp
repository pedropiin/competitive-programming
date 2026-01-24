#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535;

void solve() {
	int n; cin >> n;
	cout << fixed << setprecision(10);
	cout << 1/(long double)tan((long double)pi/(long double)(2*n)) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

