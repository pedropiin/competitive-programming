#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int l, r, d, u; cin >> l >> r >> d >> u;

	if ((l + r) != (d + u)) {
		cout << "No" << endl;
		return;
	}

	double d1 = sqrt((l * l) + (u * u));
	double d2 = sqrt((u * u) + (r * r));
	double d3 = sqrt((r * r) + (d * d));
	double d4 = sqrt((d * d) + (l * l));

	if (d1 == d2 && d2 == d3 && d3 == d4 && d4 == d1)  
		cout << "Yes" << endl;
	else 
		cout << "No" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
