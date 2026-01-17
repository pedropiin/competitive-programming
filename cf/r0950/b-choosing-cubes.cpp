#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, f, k; cin >> n >> f >> k; f--; k--;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int fav = v[f];
	sort(v.begin(), v.end(), greater<int>());

	if (k == n-1) {
		cout << "YES" << endl;
		return;
	}

	if (v[k] > fav) cout << "NO" << endl;
	else if (v[k] < fav) cout << "YES" << endl;
	else {
		if (k+1 < n && v[k+1] < fav) cout << "YES" << endl;
		else cout << "MAYBE" << endl;
	}
}

// 5 2 3
// 2 2 1 1 2 => 2 2 2 1 1

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

