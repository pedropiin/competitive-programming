#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        unordered_map<int, pair<int, int>> m;
        for (int i = 0; i < sz; i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = make_pair(1, i);
            } else {
                m[nums[i]].first++;
            }
        }
        int curr = nums[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == curr + 1) {
                ans = max(ans, m[curr].first + m[nums[i]].first);
                i = m[nums[i]].second;
            }
            curr = nums[i];
        }
        return ans;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution solve;
    cout << solve.findLHS(nums) << endl;

    return 0;
}