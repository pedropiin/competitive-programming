#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	
	ll mx_idx = -1; ll half = s/2;
	for (int i = 0; i < n; i++) {
		if (a[i] > half) {
			mx_idx = i;
			break;
		}
	}

	if (mx_idx != -1) {
		while (a[mx_idx] > s/2) {
			a[mx_idx]--;
			s--;
		}
	}

	vector<int> reps(s);
	int t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++) {
			reps[t] = i;
			t++;
		}
	}

	if (s % 2 == 0) reps.pop_back();
	half = s/2;
	cout << half << endl;
	for (int i = 0; i < half; i++) {
		cout << reps[i]+1 << " " << reps[i+half]+1 << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

