#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> odd, even;
	ll sum_odd = 0, sum_even = 0;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (i % 2 == 0) {
			even.push_back(t);
			sum_even += t;
		} else {
			odd.push_back(t);
			sum_odd += t;
		}
	}

	if ((sum_odd % odd.size() != 0) || (sum_even % even.size() != 0) || (sum_even / even.size() != sum_odd / odd.size())) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while(t--) solve();

	return 0;
}
