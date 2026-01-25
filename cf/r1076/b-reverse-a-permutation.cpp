#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n), vsorted(n);
	unordered_map<int, int> idxs;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		vsorted[i] = v[i];
		idxs[v[i]] = i;
	}
	sort(vsorted.begin(), vsorted.end(), greater<int>()); 

	int l = n-1, r = n-1;
	for (int i = 0; i < n; i++) {
		if (vsorted[i] != v[i]) {
			l = i;
			r = idxs[vsorted[i]];
			break;
		}
	}

	for (int i = 0; i < l; i++) cout << v[i] << " ";
	for (int i = r; i >= l; i--) cout << v[i] << " ";
	for (int i = r+1; i < n; i++) cout << v[i] << " ";
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

