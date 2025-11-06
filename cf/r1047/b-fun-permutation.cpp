#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	for (int val : v) cout << n + 1 - val<< " ";
	cout << endl;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
