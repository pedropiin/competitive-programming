#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		m[v[i]]++;
	}

	sort(v.begin(), v.end());
	vector<int> days;
	days.push_back(v[0]);
	int distinct_days = 1;
	for (int i = 1; i < n; i++) {
		if (v[i] != days[distinct_days-1]) {
			days.push_back(v[i]);
			distinct_days++;
		}
	}

	int flag = 0;
	for (int i = 0; i < distinct_days; i++) {
		int bet_date = days[i];
		if (m[bet_date] >= 4) {
			cout << "YES" << endl;
			return;
		} 
		if (i >= 1 && bet_date != days[i-1] + 1) {
			flag = 0;
		}
		if (m[bet_date] >= 2) {
			if (flag) {
				cout << "YES" << endl;
				return;
			} else {
				flag = 1;
				continue;
			}
		}
	}

	cout << "NO" << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
