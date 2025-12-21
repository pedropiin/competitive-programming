#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int is_prime(int n) {
	if (n % 2 == 0) return 0;
	int sqr = ceil((double)sqrt(n));
	for (int i = 3; i <= sqr; i += 2)
		if (n % i == 0) return 0;	
	return 1;
}

void solve() {
	int n; cin >> n;

	int poss = 0;
	int t = (n % 2 == 0) ? n-1 : n;
	for (int i = 2; i <= n; i += 2) {
		if (!is_prime(t+i)) {
			poss = i;
			break;
		}
	}
	
	if (poss == 0) {
		cout << "-1" << endl;
		return;
	}

	for (int i = 1; i <= n; i += 2) 
		cout << i << " ";
	cout << poss << " ";
	for (int i = 4; i <= n; i += 2) {
		if (i == poss) cout << 2 << " ";
		else cout << i << " ";
	}
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
