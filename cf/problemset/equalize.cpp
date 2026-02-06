#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	int t;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	vector<int> vec; vec.push_back(v[0]);
	for (int i = 1; i < n; i++) {
		if (v[i] != v[i-1]) vec.push_back(v[i]);
	}

	int l = 0, r = 1, sz = vec.size();
	int mx = 1;
	while (r < sz && l < sz) {
		if (vec[r] - vec[l] >= n) {
			mx = max(mx, r-l);
			l++;
			continue;
		}
		r++;
	}
	mx = max(mx, r-l);
	cout << mx << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

