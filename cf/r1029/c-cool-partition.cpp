#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<int> diff_prefix(n, 0);
	unordered_set<int> diff_elem;
	for (int i = 0; i < n; i++) {
		diff_elem.insert(v[i]);
		diff_prefix[i] = diff_elem.size();
	}

	unordered_set<int> temp;
	int num_diff = diff_prefix[n-1];
	int cnt = 0;
	for (int i = n-1; i >= 0; i--) {
		temp.insert(v[i]);
		if (temp.size() == num_diff) {
			cnt++;
			if (i == 0) {
				break;
			}
			num_diff = diff_prefix[i-1];
			temp.clear();
		}
	}
	cout << cnt << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
