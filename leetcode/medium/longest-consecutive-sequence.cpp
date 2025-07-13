#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int elem : nums) m[elem] = 0;

        int ans = 0;
        for (int elem : nums) {
            if (m[elem] != 0) continue;
            m[elem] = 1;
            int next = elem + 1;
            int count = 1;
            while (m.find(next) != m.end()) {
                if (m[next] == 0) {
                    m[next] = 1;
                    count++;
                } else {
                    count += m[next];
                    break;
                }
                next++;
            }
            m[elem] = count;
            ans = max(ans, count);
        }
        
        return ans;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> nums = {100, 4, 200, 1, 3, 2};

    Solution solve;
    cout << solve.longestConsecutive(nums) << endl;

    return 0;
}