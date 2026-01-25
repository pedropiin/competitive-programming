#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void get_divisors(set<int> &divisors, int n) {
	int sqr = ceil((double)sqrt(n));
	for (int i = 2; i <= sqr; i++) {
		if ((n%i) == 0) {
			divisors.insert(i);
			divisors.insert(n/i);
		}
	}
}

void solve() {
	int n, t; cin >> n;
	set<int> found;
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		cin >> t;
		found.insert(t);
		cnt[t] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (found.find(i) != found.end()) {
			cout << cnt[i] << " ";
		} else {
			set<int> divisors;
			get_divisors(divisors, i);
			int flag = 0;
			int min_cnt = INT_MAX;
			for (auto div : divisors) {
				int over = i/div;
				if (found.find(div) != found.end() && found.find(over) != found.end()) {
					found.insert(i);
					min_cnt = min(min_cnt, cnt[div] + cnt[over]);
					flag = 1;
				}
			}
			if (!flag) {
				cnt[i] = 0;
				cout << "-1 ";
			} else {
				cnt[i] = min_cnt;
				cout << cnt[i] << " ";
			}
		}
	}
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

