#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, x; cin >> n >> x;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());
	ll ans = 0;
	vector<int> v_ans;
	int l = 0, r = n-1;
	ll curr = 0;
	while (l <= r) {
		if (curr + v[l] >= x) {
			ans += (ll)v[r];
			curr = (ll)(curr + v[r]) % x;
			v_ans.push_back(v[r]);
			r--;
		} else {
			curr += (ll)v[l];
			v_ans.push_back(v[l]);
			l++;
		}
	}
	cout << ans << endl;
	for (int elem : v_ans) cout << elem << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

