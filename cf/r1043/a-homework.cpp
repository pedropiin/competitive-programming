#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	string a; cin >> a;
	int m; cin >> m;
	string b; cin >> b;
	string c; cin >> c;

	string v = "", d = "";
	for (int i = 0; i < m; i++) {
		if (c[i] == 'V') v += b[i];
		else d += b[i];
	}	
	
	reverse(v.begin(), v.end());
	cout << v + a + d << endl;

}

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
