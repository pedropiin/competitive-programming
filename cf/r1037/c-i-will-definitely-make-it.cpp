#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	
	int og_h = h[k-1];
	sort(h.begin(), h.end());
	for (int i = 0; i < n; i++) {
		if (h[i] == og_h) {
			k = i;
			break;
		}
	}

	if (h[k] == h[n-1]) {
		cout << "YES" << endl;
		return;
	}

	int wlvl = 1;
	for (int i = k; i < n-1; i++) {
		if (h[k] == h[n-1])	break;
		if (h[i+1] == h[k]) continue;
		if (abs(h[i+1] - h[k]) <= (abs(h[k] - wlvl) + 1)) {
			int temp = abs(h[i+1] - h[k]);
			wlvl += abs(h[i + 1] - h[k]);
			k = i + 1;
		} else {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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
