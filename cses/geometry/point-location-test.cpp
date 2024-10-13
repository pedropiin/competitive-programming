#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

		ll xtmp1, ytmp1, xtmp2, ytmp2;
		xtmp1 = (x3 - x1);
		ytmp1 = (y3 - y1);
		xtmp2 = (x3 - x2);
		ytmp2 = (y3 - y2);

		ll cross = (xtmp1 * ytmp2) - (xtmp2 * ytmp1);
		if (cross > 0) {
			cout << "LEFT" << endl;
		} else if (cross < 0) {
			cout << "RIGHT" << endl;
		} else {
			cout << "TOUCH" << endl;
		}
	}

	return 0;
}
