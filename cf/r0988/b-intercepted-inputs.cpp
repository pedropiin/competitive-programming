#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int k; cin >> k;
	vector<int> v(k);
	unordered_map<int, int> m;
	for (int i = 0; i < k; i++) {
		cin >> v[i];
		m[v[i]]++;
	}
	int goal = k-2;
	for (int i = 0; i < k; i++) {
		if (goal % v[i] != 0) continue;
		m[v[i]]--;
		if (m[goal/v[i]]) {
			cout << v[i] << " " << goal/v[i] << endl;
			break;
		}
		m[v[i]]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
