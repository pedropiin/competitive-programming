#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> rightmost_max(n, -1);
    int mx = prices[n-1];
    for (int i = n-2; i >= 0; i--) {
        mx = max(mx, prices[i]);
        rightmost_max[i] = mx;
    }

    mx = 0;
    for (int i = 0; i < n-1; i++) {
        mx = max(mx, rightmost_max[i] - prices[i]);
    }
    return mx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> prices(n);
	for (int i = 0; i < n; i++) cin >> prices[i];

	cout << maxProfit(prices) << endl;

	return 0;
}

