#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int a1, a2, a4, a5; cin >> a1 >> a2 >> a4 >> a5;
	int x;

	int sc1 = 1;
	if (2*a2 + a1 == a4) sc1++;
	if (a1 + a2 + a4 == a5) sc1++;

	int sc2 = 1;
	if (2*a2 + a1 == a4) sc2++;
	if (2*a4 - a2 == a5) sc2++;

	int sc3 = 1;
	if (a1 + a2 + a4 == a5) sc3++;
	if (a2 + a5 == 2*a4) sc3++;

	cout << max(max(sc1, sc2), sc3) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
