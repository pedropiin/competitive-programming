#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n); vector<int> b(n);

	int min_elem = 1000000007;
	int max_elem = -1;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		min_elem = min(min_elem, a[i]);
		max_elem = max(max_elem, a[i]);
	} 
	for (int i = 0; i < n; i++) cin >> b[i];

	unordered_set<int> poss_sums;
	for (int i = 0; i < n; i++) {
		if (b[i] != -1) poss_sums.insert(a[i] + b[i]);
	}

	if (poss_sums.size() > 1) {
		cout << 0 << endl;
		return;
	}

	if (poss_sums.size() == 1) {
		int t = *poss_sums.begin();
		for (int elem : a) {
			if ((elem > t) || (t-elem > k)) {
				cout << 0 << endl; return;
			}
		}
		cout << 1 << endl; return;
	} else {
		int min_poss_sum = max_elem;
		int max_poss_sum = min_elem + k;
		if (min_poss_sum > max_poss_sum) {
			cout << 0 << endl; return;
		}
		cout << max_poss_sum-min_poss_sum+1 << endl;
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
