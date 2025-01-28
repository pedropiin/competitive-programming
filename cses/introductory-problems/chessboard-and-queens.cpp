#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> board(8, vector<int>(8));

int q;
int ans;
int row;
int col;

void backtrack();
void solve();

int valid(int row, int col) {
    
    // checking blockage
    if (board[row][col] == -1) {
        return 0;
    }
    // checking row 
    for (int j = 0; j < 8; j++) {
        if (board[row][j] == 1) {
            return 0;
        }
    }
    // checking column
    for (int i = 0; i < 8; i++) {
        if (board[i][col] == 1) {
            return 0;
        }
    }
    // checking diagonal 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (abs(row - i) == abs(col - j)) {
                if (board[i][j] == 1) {
                    return 0;
                }
            }
        }
    }
    
    // if here, it is valid
    return 1;
}

void backtrack() {
    row--;
    for (int j = 7; j >= 0; j--) {
        if (board[row][j] == 1) {
            board[row][j] = 0;
            q++;
            col = j + 1;
            break;
        }
    }
}

void solve() {
    int end = 0;
    while (!end) {
        if (row > 7) {
            if (q == 0) {
                ans++;
            } 
            backtrack();
        } else {
            int found = 0;
            for (int j = col; j < 8; j++) {
                if (valid(row, j)) {
                    board[row][j] = 1;
                    q--;
                    found = 1;
                    break;
                }
            }

            if (found) {
                row++;
                col = 0;
            } else {
                if (row == 0) {
                    end = 1;
                } else {
                    backtrack();
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char t;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> t;
            if (t == '.') {
                board[i][j] = 0;
            } else {
                board[i][j] = -1;
            }
        }
    }

    q = 8;
    row = 0;
    col = 0;
    solve();
    cout << ans << endl;

    return 0;
}
