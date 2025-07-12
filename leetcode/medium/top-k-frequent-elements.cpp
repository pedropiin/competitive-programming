#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<pair<int, int>> freq;
        freq.push_back({nums[0], 1});
        int uniq = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                freq[uniq].second++;
            } else {
                freq.push_back({nums[i], 1});
                uniq++;
            }
        }
        sort(freq.begin(), freq.end(), 
            [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
                return a.second > b.second;
            }
        );
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << Solution.topKFrequent(nums, k) << endl;

    return 0;
}