#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	string a, b; cin >> a >> b;
	vector<int> freqa(27, 0), freqb(27, 0);
	for (int i = 0; i < n; i++) {
		freqa[a[i]-'a']++;
		freqb[b[i]-'a']++;
	}

	for (int i = 0; i < 26; i++) {
		int diff = freqa[i] - freqb[i];
		if (diff < 0 || diff % k) {
			cout << "NO" << endl;
			return;
		}
		freqa[i+1] += diff;	
	}
	cout << "YES" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

