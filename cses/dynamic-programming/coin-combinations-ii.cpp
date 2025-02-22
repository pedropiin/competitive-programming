#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    sort(c.begin(), c.end());

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for (int coin : c) {
        for (int j = 0; j <= x; j++) {
            if (j - coin >= 0) {
                dp[j] += dp[j - coin];
                dp[j] %= mod;
            }
        }
    }

    cout << dp[x] << endl;

    return 0;
}