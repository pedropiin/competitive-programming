#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, a, b;
	cin >> n >> a >> b;

	int max = 6 * n + 1;
	vector<vector<double>> dp(n + 1, vector<double>(max + 1, 0));
	
	dp[0][0] = 1.0;
	const int poss = 6;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= max; j++) {
			for (int k = 1; k <= 6; k++) {
				if ((j - k) >= 0) {
					dp[i][j] += dp[i - 1][j - k] / poss;
				}
			}
		}
	}

	double count = 0;
	for (int i = a; i <= b; i++) {
		count += dp[n][i];
	}
	cout << setprecision(6) << fixed;
	cout << count << endl;

	return 0;
}
