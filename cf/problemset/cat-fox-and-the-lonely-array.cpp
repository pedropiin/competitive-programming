#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int check_k(vector<int> &v, int k, int n) {
	vector<int> t(21, 0);
	int og_or = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 21; j++) {
			if (v[i] & (1 << j)) 
				t[j]++;
		}
		og_or = og_or | v[i];
	}

	for (int i = 1; i < (n-k+1); i++) {
		int prev = v[i-1];
		for (int j = 0; j < 21; j++) {
			if (prev & (1 << j)) 
				t[j]--;
		}
		int curr = v[i+k-1];
		for (int j = 0; j < 21; j++) {
			if (curr & (1 << j)) 
				t[j]++;
		}
		int curr_or = 0;
		for (int j = 0; j < 21; j++) {
			if (t[j] > 0) 
				curr_or |= (1 << j);
		}
		if (curr_or != og_or) {
			return 0;
		}
	}
	return 1;
}

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int l = 1, r = n;
	while (l < r) {
		int m = l + (r-l)/2;
		if (check_k(v, m, n)) {
			r = m;
		} else {
			l = m+1;
		}
	}
	cout << l << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

