#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<char>> board(1001, vector<char> (1001));
vector<vector<int>> cor(1001, vector<int> (1001));

void dfs(int x, int y, int n, int m) {
    cor[x][y] = 1;
    int xtemp, ytemp;
    
    xtemp = x + 1;
    ytemp = y;
    if (xtemp >= 0 && xtemp < n && ytemp >= 0 && ytemp < m && board[xtemp][ytemp] != '#') {
        if (cor[xtemp][ytemp] == 0) {
            dfs(xtemp, ytemp, n, m);
        }
    }
    xtemp = x - 1;
    ytemp = y;
    if (xtemp >= 0 && xtemp < n && ytemp >= 0 && ytemp < m && board[xtemp][ytemp] != '#') {
        if (cor[xtemp][ytemp] == 0) {
            dfs(xtemp, ytemp, n, m);
        }
    }
    xtemp = x;
    ytemp = y + 1;
    if (xtemp >= 0 && xtemp < n && ytemp >= 0 && ytemp < m && board[xtemp][ytemp] != '#') {
        if (cor[xtemp][ytemp] == 0) {
            dfs(xtemp, ytemp, n, m);
        }
    }
    xtemp = x;
    ytemp = y - 1;
    if (xtemp >= 0 && xtemp < n && ytemp >= 0 && ytemp < m && board[xtemp][ytemp] != '#') {
        if (cor[xtemp][ytemp] == 0) {
            dfs(xtemp, ytemp, n, m);
        }
    }
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            cor[i][j] = 0;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.' && cor[i][j] == 0) {
                dfs(i, j, n, m);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}

