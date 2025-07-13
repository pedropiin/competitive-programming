#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans;
        int l = 0, r = n - 1;
        int temp;
        while (l < r) {
            temp = numbers[l] + numbers[r];
            if (temp > target) r--;
            else if (temp < target) l++;
            else {
                ans.push_back(l + 1);
                ans.push_back(r + 1);
                break;
            }
        }
        return ans;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> numbers = {2,7,11,15};
    int target = 9;

    Solution solve;
    cout << solve.twoSum(numbers, target) << endl;

    return 0;
}