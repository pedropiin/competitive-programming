#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9

vector<int> dist;
vector<int> pred;

int min(int a, int b, int c) {
	return min(min(a, b), c);
}

void backtrack(vector<vector<int>> &dp, int i, int j, vector<pair<int, pair<int, char>>> &ans, string &s2) {
    int change_i = 0, change_j = 0;
    if (dp[i][j] > 0) {
        int corner = 0;
        if ((i - 1) < 0) {
            corner = 1;
        } else if ((j - 1) < 0) {
            corner = 2;
        }

        if (corner == 0) {
            // normal case
            int curr = dp[i][j];
            int left = dp[i][j - 1];
            int diag = dp[i - 1][j - 1];
            int up = dp[i - 1][j];

            if (left < diag && left < up) {
                if (left != curr) {
                    // inserted element
                    ans.push_back(make_pair(0, make_pair(i, s2[j])));
                    change_j = 1;
                }
            } else if (up < diag && up < left) {
                if (up != curr) {
                    // deleted element
                    ans.push_back(make_pair(1, make_pair(i, '0')));
                    change_i = 1;
                }
            } else if (diag < left && diag < up) {
                if (diag != curr) {
                    // replaced element
                    ans.push_back(make_pair(2, make_pair(i, s2[j])));
                    change_i = 1;
                    change_j = 1;
                }
            }
        } else if (corner == 1) {
            // top row
            int curr = dp[i][j];
            int left = dp[i][j - 1];
            if (left != curr) {
                ans.push_back(make_pair(0, make_pair(i, s2[j])));
            }
            change_j = 1;
        } else if (corner == 2) {
            // left column
            int curr = dp[i][j];
            int up = dp[i - 1][j];
            if (up != curr) {
                ans.push_back(make_pair(1, make_pair(i, '0')));
            }
            change_i = 1;
        }
        
        backtrack(dp, (i - change_i), (j - change_j), ans, s2);
    }
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    while (cin >> s1) {
        cin >> s2;

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

        vector<pair<int, pair<int, char>>> ans;
        backtrack(dp, n1, n2, ans, s2);

        int count = 1;
        for (int i = ans.size() - 1; i >= 0; i--) {
            if (ans[i].first == 0) {
                cout << count << " Insert " << ans[i].second.first << ',' << ans[i].second.second << endl;
            } else if (ans[i].first == 1) {
                cout << count << " Delete " << ans[i].second.first << endl;
            } else {
                cout << count << " Replace " << ans[i].second.first << ',' << ans[i].second.second << endl;
            }
        }
    }

    return 0;
}