#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<vector<int>> m(n, vector<int>(n, -1));
    m[0][0] = 0;
    queue<vector<int>> q;
    vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    
    for (pair<int, int> p : moves) {
        if (p.first >= 0 && p.first < n && p.second >= 0 && p.second < n && m[p.first][p.second] == -1) {
            m[p.first][p.second] = 1;
            q.push({1, p.first, p.second});
        }
    }

    int cnt, curr_x, curr_y;
    int tx, ty;
    while (!q.empty()) {
        cnt = q.front()[0], curr_x= q.front()[1], curr_y = q.front()[2];
        q.pop();

        for (auto p : moves) {
            tx = curr_x + p.first; ty = curr_y + p.second;
            if (tx >= 0 && tx < n && ty >= 0 && ty < n && m[tx][ty] == -1) {
                m[tx][ty] = cnt + 1;
                q.push({cnt + 1, tx, ty});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << m[i][j] << " ";
        cout << endl;
    }

    return 0;
}
