#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int found = -1;
        while (l < r) {
            int m = l + ((r - l) / 2);
            if (target > nums[m]) l = m + 1;
            else if (target < nums[m]) r = m - 1;
            else {
                found = m;
                break;
            }
        }
        return found;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 2;

    Solution solve;
    cout << solve.search(nums, target) << endl;

    return 0;
}