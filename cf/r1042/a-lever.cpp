#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> b[i];
	
	int step1 = 1;
	int ans = 0;
	while (step1) {
		int change = 0;
		ans++;	
		for (int i = 0; i < n; i++) {
			if (a[i] > b[i]) {
				a[i]--;
				change = 1;
				break;
			}
		}
		if (!change) step1 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < b[i]) {
				a[i]++;
				break;
			}
		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	cin.tie(0);
}
