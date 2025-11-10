#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k;
	cin >> n >> k;
	int temp; int mod; map<int ,int> freq; 
	for (int i = 0; i < n; i++) {
		cin >> temp; mod = temp % k;
		freq[mod]++;
		freq[k-mod]++;
	}
	for (int i = 0; i < n; i++) {
		cin >> temp; mod = temp % k;
		freq[mod]--;
		freq[k-mod]--;
	}

	int ans = 1;
	map<int, int>::iterator it;
	for (it = freq.begin(); it != freq.end(); it++) {
		if (it->second != 0) {
			ans = 0;
			break;
		}
	}
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
