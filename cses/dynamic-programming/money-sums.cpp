#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	int sm = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sm += v[i];
	}

	vector<int> t(sm+1, 0), has(sm+1, 0);
	int cnt;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		t.clear();
		cnt = 0;

		t[cnt++] = v[i];
		for (int j = 1; j <= sm; j++) {
			if (has[j] != 0) t[cnt++] = j + v[i];
		}

		for (int j = 0; j < cnt; j++) {
			if (has[t[j]] == 0) ans++;
			has[t[j]] = 1;
		}
	}

	cout << ans << endl;
	for (int i = 1; i <= sm; i++) if (has[i] == 1) cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();
		
	return 0;
}

