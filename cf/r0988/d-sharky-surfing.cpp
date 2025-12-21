#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m, l; cin >> n >> m >> l;
	vector<pair<int, int>> hurdles;
	int t1, t2;
	for (int i = 0; i < n; i++) {
		cin >> t1 >> t2;
		if (i > 0 && hurdles[i-1].second + 1 == t1) 
			hurdles[i-1].second = t2;
		else 
			hurdles.push_back(make_pair(t1, t2));
	}
	n = hurdles.size();
	vector<pair<int, int>> powers(m);
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		powers[i] = make_pair(t1, t2);
	}

	int ans = 0;
	ll k = 1;
	int next_power_idx = 0;
	int poss = 1;
	priority_queue<int> available_powers;
	for (int i = 0; i < n; i++) {
		int j;	
		for (j = next_power_idx; j < m; j++) {
			if (powers[j].first < hurdles[i].first) available_powers.push(powers[j].second);
			else break;
		}
		next_power_idx = j;

		int obst = hurdles[i].second - hurdles[i].first + 2;
		while (k < obst && available_powers.size() > 0) {
			k += available_powers.top();
			available_powers.pop();
			ans++;
		}
		
		if (k < obst) {
			poss = 0;
			break;
		}
	}		

	if (!poss) cout << -1 << endl;
	else cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
