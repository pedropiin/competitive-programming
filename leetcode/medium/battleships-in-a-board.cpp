#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int countBattleships(vector<vector<char>>& board) {
    int ans = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'X') {
                ans++;
                int ti = i+1, tj = j+1;
                bool right_flag = false;
                while (tj < board[i].size() && board[i][tj] == 'X') {
                    tj++;
                    right_flag = true;
                }
                if (right_flag) {
                    j = tj;
                    continue;
                }
                while (ti < board.size() && board[ti][j] == 'X') {
                    board[ti][j] = '.';
                    ti++;
                }
            }
        }
    }

    return ans;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<char>> board;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> board[i][j];
    cout << countBattleships(board) << endl;

    return 0;
}
