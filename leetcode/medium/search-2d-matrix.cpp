#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m - 1;
        int col;
        while (l <= r) {
            col = l + (r - l) / 2;
            if (matrix[col][0] <= target && matrix[col][n - 1] >= target) {
                break;
            }
            if (matrix[col][0] < target) l = col + 1;
            else r = col - 1;
        }
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[col][mid] == target) return true;

            if (matrix[col][mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;

    Solution solve;
    cout << solve.searchMatrix(matrix, target) << endl;

    return 0;
}