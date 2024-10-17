#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

int min(int a, int b, int c) {
	return min(min(a, b), c);
}

int main (int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	int n1 = s1.size(), n2 = s2.size();
	vector<vector<int>> dp((n1 + 1), vector<int> (n2 + 1, INF));

	for (int i = 0; i <= n2; i++) {
		dp[0][i] = i;
	}
	for (int j = 0; j <= n1; j++) {
		dp[j][0] = j;
	}

	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			int cost = 1;
			if (s1[i - 1] == s2[j - 1]) {
				cost = 0;
			}
			dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost);
		}
	}


	cout << dp[n1][n2] << endl;

	return 0;
}
