#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string a; cin >> a;
	string b; cin >> b;
	string c; cin >> c;

	int asize = a.length();
	int bsize = b.length();
	int csize = c.length();

	vector<vector<int>> dp(asize+1, vector<int>(bsize+1));
	dp[0][0] = 0;
	for (int i = 1; i <= asize; i++) 
		dp[i][0] = (a[i-1] == c[i-1]) ? dp[i-1][0] : dp[i-1][0] + 1;
	for (int j = 1; j <= bsize; j++) 
		dp[0][j] = (b[j-1] == c[j-1]) ? dp[0][j-1] : dp[0][j-1] + 1;

	int tooka, tookb;
	for (int i = 1; i <= asize; i++) {
		for (int j = 1; j <= bsize; j++) {
			tooka = (a[i-1] == c[i+j-1])^1;
			tookb = (b[j-1] == c[i+j-1])^1;
			dp[i][j] = min(dp[i-1][j] + tooka, dp[i][j-1] + tookb);
		}
	}

	cout << dp[asize][bsize] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
