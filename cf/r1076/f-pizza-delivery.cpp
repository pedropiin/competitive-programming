#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dist(pair<int, int> &curr, pair<int, int> &src) {
	return abs(curr.first - src.first) + abs(curr.second - src.second);
}

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> v(n+2, pair<int, int>());
	cin >> v[0].first >> v[0].second >> v[1].first >> v[1].second;
	for (int i = 0; i < n; i++) cin >> v[i+2].first;
	for (int i = 0; i < n; i++) cin >> v[i+2].second;
	n += 2;

	sort(v.begin(), v.end());
	vector<pair<int, int>> points;
	points.push_back(v[0]);
	int i = 1;
	while (i < n) {
		int j = i+1;
		points.push_back(v[i]);
		while (j < n && v[i].first == v[j].first) j++;
		if (i != j-1) points.push_back(v[j-1]);
		i = j;
	}

	int relevant_n = points.size();
	vector<ll> dp(relevant_n);
	dp[0] = (ll)0;
	for (int i = 1; i < relevant_n; i++) {
		pair<int, int> low = {-1, -1}, high = {-1, -1};
		int low_idx = -1, high_idx = -1;
		if (points[i].first != points[i-1].first) {
			high = points[i-1];
			high_idx = i-1;
			if (i-1 > 0 && points[i-1].first == points[i-2].first) {
				low = points[i-2];
				low_idx = i-2;
			}
		} else {
			high = points[i-2];
			high_idx = i-2;
			if (i-2 > 0 && points[i-2].first == points[i-3].first) {
				low = points[i-3];
				low_idx = i-3;
			} 
		}

		if (low_idx == -1) {
			dp[i] = dp[high_idx] + (ll)dist(points[i], high);
		} else {
			ll line_len = (ll)dist(high, low);
			dp[i] = min(
					(ll)(dp[low_idx] + line_len + (ll)dist(points[i], high)),
					(ll)(dp[high_idx] + line_len + (ll)dist(points[i], low))
					);
		}
	}
	
	cout << dp[relevant_n-1] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

