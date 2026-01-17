#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int get_gcd(int a, int b) {
	while (b != 0) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

int poss_without(vector<int> &og, vector<int> &cp, int n, int idx) {
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (i == idx) continue;
		else {
			cp[t] = og[i];
			t++;
		}
	}

	int prev = get_gcd(cp[0], cp[1]);
	int curr;
	for (int i = 1; i < n-2; i++) {
		curr = get_gcd(cp[i], cp[i+1]);
		if (prev <= curr) prev = curr;
		else {
			return 0;
		}
	}
	return 1;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	if (n == 3) {
		cout << "YES" << endl;
		return;
	}

	int flag = -1;
	int prev = get_gcd(a[0], a[1]);
	int curr;
	for (int i = 1; i < n-1; i++) {
		curr = get_gcd(a[i], a[i+1]);
		if (prev <= curr) {
			prev = curr;
		} else {
			flag = i;
			break;
		}
	}	

	if (flag != -1) {
		vector<int> cp(n-1);

		// without previous element
		int t1 = poss_without(a, cp, n, flag-1);
		int t2 = poss_without(a, cp, n, flag);
		int t3 = poss_without(a, cp, n, flag+1);
		if (!t1 && !t2 && !t3) {
			cout << "NO" << endl; return;
		}
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

