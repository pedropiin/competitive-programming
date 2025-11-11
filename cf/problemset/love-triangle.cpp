#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	int ans = 0;
	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = 0; i < n; i++) {
		int l1 = v[i];
		int l2 = v[l1-1];
		int l3 = v[l2-1];
		if (i == (l3-1)) {
			ans = 1;
			break;
		}
	}
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
