#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void clockwise(int &i, int &j, int &n, int &m, int mod) {
	int t1 = i, t2 = j;
	switch (mod) {
		case 0:
			return;
		case 1:
			i = j;
			j = n-t1+1;
			swap(n, m);
			return;
		case 2:
			i = n-t1+1;
			j = m-t2+1;
			return;
		case 3:
			i = m-t2+1;
			j = t1;
			swap(n, m);
			return;
	}
}

void solve() {
	int n, m, x, y, z, p; cin >> n >> m >> x >> y >> z >> p;

	int i, j;
	for (int _ = 0; _ < p; _++) {
		cin >> i >> j;
		int n_it = n, m_it = m;
		clockwise(i, j, n_it, m_it, x % 4);
		if (y % 2 != 0) {
			j = m_it-j+1;
		}
		int mod = z % 4;
		switch (mod) {
			case 0:
				break;
			case 1:
				clockwise(i, j, n_it, m_it, 3);
				break;
			case 2:
				clockwise(i, j, n_it, m_it, 2);
				break;
			case 3:
				clockwise(i, j, n_it, m_it, 1);
				break;
		}
		cout << i << " " << j << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

