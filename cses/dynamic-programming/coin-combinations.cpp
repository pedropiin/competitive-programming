#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	vector<ll> dp((x + 1), 0);
	dp[0] = 1;
	for (int i = 1; i <= x; i++) {
		for (int c : coins) {
			if ((i - c) >= 0) {
				dp[i] += dp[i - c];
				dp[i] %= MOD;
			}
		}
	}

	cout << dp[x] << endl;

	return 0;
}
