#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());

	int ans = 0; int i = n-1;
	while (i >= 0 && a[i] >= x) {
		ans++;
		i--;
	}

	while (i >= 0) {
		int s = a[i];
		int min_curr_team = a[i]; int sz_curr_team = 1;
		int j = i-1;
		for (j = i-1; j >= 0; j--) {
			min_curr_team = min(min_curr_team, a[j]);
			sz_curr_team++;
			s = sz_curr_team * min_curr_team;
			if (s >= x) {
				ans++;
				break;
			}
		}
		i = j-1;
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
