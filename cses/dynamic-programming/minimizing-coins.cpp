#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	vector<int> count((x + 1), INF);
	count[0] = 0;
	for (int i = 1; i <= x; i++) {
		for (int j : coins) {
			if ((i - j) >= 0) {
				count[i] = min(count[i], count[i - j] + 1);
			}
		}
	}

	if (count[x] < INF) {
		cout << count[x] << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}
