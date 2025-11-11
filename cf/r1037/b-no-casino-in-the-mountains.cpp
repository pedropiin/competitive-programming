#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int i = 0;
	int ans = 0, hike_cnt = 0, cnt = 0;
	while (i < n) {
		if (a[i] == 0) {
			i++;
			cnt++;
			if (cnt == k) {
				hike_cnt += 1;
				ans = max(ans, hike_cnt);
				i++;
				cnt = 0;
			}
		} else {
			cnt = 0;
			i++;
		}
	}
	cout << ans << endl;
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
