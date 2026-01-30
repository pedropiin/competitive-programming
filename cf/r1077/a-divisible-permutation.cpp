#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	int half = n/2 + 1;
	vector<int> upper, lower;
	for (int i = half; i <= n; i++) upper.push_back(i);
	for (int i = half-1; i >= 1; i--) lower.push_back(i);

	if (n % 2 == 0) {
		for (int i = 0; i < n/2; i++) {
			cout << upper[i] << " " << lower[i] << " ";
		}
		cout << endl;
	} else {
		for (int i = 0; i < n/2; i++) {
			cout << upper[i] << " " << lower[i] << " ";
		}
		cout << upper[n/2] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

