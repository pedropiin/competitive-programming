#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<vector<char>> m(n, vector<char>(n));
	char t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(n, 0));
	int has_ast = 0;
	for (int j = 0; j < n; j++) {
		if (m[0][j] == '*') {
			has_ast = 1;
		}
		if (has_ast) {
			dp[0][j] = 0;
		} else {
			dp[0][j] = 1;
		}
	}
	has_ast = 0;
	for (int i = 0; i < n; i++) {
		if (m[i][0] == '*') {
			has_ast = 1;
		}
		if (has_ast) {
			dp[i][0] = 0;
		} else {
			dp[i][0] = 1;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (m[i][j] == '*') {
				dp[i][j] = 0;
			} else {
				dp[i][j] = ((ll)dp[i][j - 1] + (ll)dp[i - 1][j]) % mod;
			}
		}
	}

	cout << dp[n - 1][n - 1] << endl;

	return 0;
}
