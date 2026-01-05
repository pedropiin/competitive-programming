#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool canPartition(vector<int>& nums) {
    long long int summ = 0;
    for (int elem : nums) summ += elem;

    if (summ % 2 != 0) return false;

    long long int half_summ = summ / 2;
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(half_summ + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= half_summ; j++) {
            if (nums[i-1] > j) {
                dp[i][j] = dp[i-1][j]; continue;
            }

            dp[i][j] = max(dp[i-1][j], dp[i-1][j - nums[i-1]]);
        }
    }

    return dp[n][half_summ];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << canPartition(nums) << endl;

    return 0;
}
