#include <bits/stdc++.h>

using namespace std;

// 2, 2, 6, 10, 11, 18, 18, 28, 34, 37, 39, 40, 45, 47, 49, 57, 63, 68, 68, 68, 72, 75, 84, 91, 93, 97

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	int even = 0, odd = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		(v[i] % 2 == 0) ? even++ : odd++;
	} 

	if ((even % 2) != (odd % 2)) {
		cout << "NO" << endl;
		return;
	} else if (even % 2 == 0 && odd % 2 == 0) {
		cout << "YES" << endl;
		return;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n-1; i++) {
		if (v[i] + 1 == v[i+1]) {
			even--;
			odd--;
			break;
		}
	}
	
	if (even % 2 == 0 && odd % 2 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
