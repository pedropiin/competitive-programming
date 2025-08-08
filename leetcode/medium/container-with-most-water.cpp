#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            ans = max(ans, (r - l) * min(height[l], height[r]));
            if (height[l] <= height[r]) l++;
            else r--;
        }
        return ans;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution solve;
    cout << solve.maxArea(height) << endl;

    return 0;
}