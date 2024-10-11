#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	vector<int> price(n), page(n);
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> page[i];
	}

	vector<vector<int>> dp((n + 1), vector<int>((x + 1), 0));

	for (int i = 0; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (i - price[j] >= 0) {
				if ((j - 1) >= 0) {
					dp[i][j] = max(max(dp[i][j], dp[i - price[j]][j] + page[j]), dp[i][j - 1]);
				} else {
					dp[i][j] = max(dp[i][j], dp[i - price[j]][j] + page[j]);
				}
			}
		}
	}

	

	return 0;
}
