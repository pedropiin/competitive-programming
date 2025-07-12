#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int sz = nums.size();
        int curr;
        vector<int> ans;
        for (int i = 0; i < sz; i++) {
            curr = target - nums[i];
            if (m.find(curr) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[curr]);
                break;
            } else {
                m[nums[i]] = i;
            }
        }
        return ans;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << Solution.twoSum(nums, target);

    return 0;
}