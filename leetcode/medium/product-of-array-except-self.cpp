#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix; prefix.push_back(1);
        vector<int> suffix; suffix.push_back(1);
        for (int i = 0; i < n; i++) prefix.push_back(nums[i] * prefix[i]);
        for (int i = n - 1; i >= 0; i--) suffix.push_back(nums[i] * suffix[n - 1 - i]);
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) ans.push_back(suffix[i] * prefix[n - 1 - i]);
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
    cout << solve.productExceptSelf(nums) << endl;

    return 0;
}