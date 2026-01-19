#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {	
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int rounds = n/k + (n%k != 0);
	int minn = INT_MAX, ans = 1;
	for (int i = 0; i < k; i++) {
		int temp = 0;
		for (int j = 0; j < rounds; j++) {
			temp += v[(i + j*k) % n];
		}
		if (temp < minn) {
			minn = temp;
			ans = i;
		}
	}
	cout << ans+1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

