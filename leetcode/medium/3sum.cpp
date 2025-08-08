#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long long int ll;

typedef long long int ll;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_set<string> s;
        for (int elem : nums) freq[elem]++;
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if (t == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    string hash = to_string(temp[0]) + "," + to_string(temp[1]) + "," + to_string(temp[2]);
                    if (s.find(hash) == s.end()) {
                        ans.push_back(temp);
                        s.insert(hash);
                    }
                    j++;
                    while (nums[j] == nums[j - 1] && j < k) j++;
                } else if (t < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> nums = {0, 0, 0, 0};
    Solution solve;
    auto ans = solve.threeSum(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    }

    return 0;
}