#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int a, m; cin >> a >> m;

	set<int> s; 
	int prev = a, next = a%m;
	while (1) {
		if (next == 0) {
			cout << "Yes" << endl; return;
		}
		if (s.find(next) != s.end()) {
			cout << "No" << endl; return;
		}
		s.insert(next);
		prev += next;
		next = prev%m;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

