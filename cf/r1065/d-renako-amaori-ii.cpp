#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int max_bits = 20;

void solve() {
	int n; cin >> n;
	vector<int> a(n); vector<int> b(n);
	int total_xor = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total_xor ^= a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		total_xor ^= b[i];
	}

	int high_diff_bit = -1;
	int t = 1;
	for (int i = 0; i < max_bits; i++) {
		if (total_xor & t) high_diff_bit = i;	
		t = t << 1;
	}

	if (high_diff_bit == -1) {
		cout << "Tie" << endl;
		return;
	}

	t = 1 << high_diff_bit;
	int high_diff_idx = -1;
	for (int i = 0; i < n; i++) 
		if ((a[i] ^ b[i]) & t) high_diff_idx = i;

	if (high_diff_idx % 2 == 0) cout << "Ajisai" << endl;
	else cout << "Mai" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
