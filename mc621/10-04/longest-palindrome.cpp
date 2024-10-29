#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve(vector<vector<int>> &dp, string &s, int left, int right) {
    if (dp[left][right] != -1 || left >= right) {
        return dp[left][right];
    } 

    if (s[left] == s[right]) {
        dp[left][right] = 2 + solve(dp, s, left + 1, right - 1);
        return dp[left][right];
    } else {
        int t1 = solve(dp, s, left + 1, right);
        int t2 = solve(dp, s, left, right - 1);
        dp[left][right] = max(t1, t2);
        return dp[left][right];
    }
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        int n = s.size();
        vector<vector<int>> dp((n + 1), vector<int>((n + 1), -1));

        for (int i = 0; i <= n; i++) {
            dp[i][i] = 1;
        }
        for (int j = 0; j < n; j++) {
            for (int i = j + 1; i <= n; i++) {
                dp[i][j] = 0;
            }
        }

        int ans = solve(dp, s, 0, n - 1);

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
        cout << ans << endl;
    }

    return 0;
}
