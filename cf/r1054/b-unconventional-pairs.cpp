#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i += 2) {
		ans = max(ans, abs(v[i] - v[i + 1]));
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
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
