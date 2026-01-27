#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> v(m);
	ll sm = 0;
	for (int i = 0; i < m; i++) {
		cin >> v[i];
		sm += (ll)v[i];
	}

	ll delta = sm - (ll)n;
	if (delta < 0) {
		cout << -1 << endl;
		return;
	}

	for (int i = m-1; i >= 0; i--) {
		if (n - v[i] < i) {
			cout << -1 << endl;
			return;
		}
	}

	int i = 0;
	while (i < m && delta > 0) {
		int temp = v[i]-1;
		if (temp <= delta) {
			v[i] = 1;
			delta -= temp;
		} else {
			v[i] -= delta;
			break;
		}
		i++;
	}

	int ans = 1;
	for (int i = 0; i < m; i++) {
		cout << ans << " ";
		ans += v[i];
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t = 1;
	while (t--) solve();

	return 0;
}

