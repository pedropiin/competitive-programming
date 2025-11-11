#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<tuple<int, int, int>> casinos(n);
	int t1, t2, t3;
	for (int i = 0; i < n; i++) {
		cin >> t1 >> t2 >> t3;
		casinos[i] = make_tuple(t1, t2, t3);	
	}

	sort(casinos.begin(), casinos.end(), [](const tuple<int, int, int>& l, const tuple<int, int, int> &r) {
		return get<0>(l) < get<0>(r);
	});

	for (int i = 0; i < n; i++) {
		tuple<int, int, int> curr = casinos[i];
		if (get<0>(curr) <= k && get<2>(curr) > k) {
			k = get<2>(curr);
		}
	}	
	cout << k << endl;
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
