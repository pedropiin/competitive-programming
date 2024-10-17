#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int max(int a, int b, int c) {
	return max(max(a, b), c);
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	vector<int> price(n), pages(n);
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> pages[i];
	}

	vector<int> dp(x + 1, 0);

	for (int i = 0; i < n; i++) {
		for (int j = x; j >= 0; j--) {
			if (j - price[i] >= 0) {
				dp[j] = max(dp[j], (dp[j - price[i]] + pages[i]));
			}
		}
	}
	
	cout << dp[x] << endl;

	return 0;
}
