#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void bfs(vector<vector<char>> &grid, int i, int j, int n, int m) {
    grid[i][j] = '0';
    if (j + 1 < m && grid[i][j+1] == '1') bfs(grid, i, j+1, n, m);
    if (j - 1 >= 0 && grid[i][j-1] == '1') bfs(grid, i, j-1, n, m);
    if (i + 1 < n && grid[i+1][j] == '1') bfs(grid, i+1, j, n, m);
    if (i - 1 >= 0 && grid[i-1][j] == '1') bfs(grid, i-1, j, n, m);
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                ans++;
                bfs(grid, i, j, n, m);
            }
        }
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<char>> grid;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> grid[i][j];
	}

	cout << numIslands(grid) << endl;

	return 0;
}

