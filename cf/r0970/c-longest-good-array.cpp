#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll l, r; cin >> l >> r;
	ll d = floor((double)sqrt((ll)1+(ll)8*(ll)(r-l)));
	cout << (-1+d)/2 + 1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

