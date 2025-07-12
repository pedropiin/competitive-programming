#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, int>> f_board(27, unordered_map<int, int>());
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j] - '0';
                if (c >= 0) {
                    f_board[i][c]++;
                    f_board[j + 9][c]++;
                    f_board[18 + (i / 3) * 3 + (j / 3)][c]++;
                }
            }
        }
        bool ans = true;
        for (int i = 0; i < 27; i++) {
            for (int j = 0; j < 10; j++) {
                if (f_board[i][j] > 1) {
                    ans = false;
                    break;
                }
            }
            if (!ans) break;
        }
        return ans;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<char>> board(9, vector<char>(9, '.'));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) cin >> board[i][j];

    cout << Solution.isValidSudoku(board) << endl;

    return 0;
}