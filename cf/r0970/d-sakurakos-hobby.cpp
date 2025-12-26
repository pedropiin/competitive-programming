#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t; t--;
		v[i] = t;
	}
	string s; cin >> s;

	vector<int> visited(n, 0);
	vector<int> cycle_elems;
	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++) {
		if (visited[i] == 1) continue;
		t = v[i];
		visited[i] = 1;
		cycle_elems.push_back(i);
		while (visited[t] == 0 && t != v[t]) {
			cycle_elems.push_back(t);
			visited[t] = 1;
			t = v[t];
		}
		int cycle_sz = cycle_elems.size();
		int blacks = 0;
		for (int elem : cycle_elems) 
			if (s[elem] == '0') blacks++;
		for (int elem : cycle_elems) 
			ans[elem] = blacks;
		cycle_elems.clear();
	}

	for (int elem : ans) cout << elem << " ";
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

