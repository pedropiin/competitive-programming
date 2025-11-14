#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;

	vector<int> v(4, 0);
	for (int i = 0; i < n; i++) {
		v[i % 4]++;
	}

	if (v[0] != v[3] || v[1] != v[2]) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
