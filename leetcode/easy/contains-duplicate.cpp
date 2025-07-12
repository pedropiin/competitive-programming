#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        int sz = nums.size();
        bool found = false;
        for (int i = 0; i < sz; i++) {
            if (s.contains(nums[i])) {
                found = true;
                break;
            } else {
                s.insert(nums[i]);
            }
        }
        return found;
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

    bool result = Solution.containsDuplicate(nums);
    cout << result << endl;

    return 0;
}