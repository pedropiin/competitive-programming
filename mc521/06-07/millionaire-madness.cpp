#include <bits/stdc++.h>

#define MAX 1000

using namespace std;

typedef long long ll;

bool taken[MAX][MAX];
int h[MAX][MAX];
priority_queue<pair<int, pair<int, int>>> pq;
vector<pair<int, int>> neighbors = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void process(int i, int j, int m, int n) {
    taken[i][j] = true;
    for (auto &[diff_i, diff_j] : neighbors) {
        int row = i + diff_i;
        int col = j + diff_j;;
        
        if (row >= 0 && row < m && col >= 0 && col < n && !taken[row][col])  {
            int w = max(0, h[row][col] - h[i][j]);
            pq.push({-w, {row, col}});
        }
    }
}

int prim(int s_i, int s_j, int m, int n) {
    process(s_i, s_j, m, n);
    int max_cost = 0;
    
    while (!pq.empty() && !taken[m - 1][n - 1]) {
        auto [w, ij] = pq.top();
        pq.pop();
        w = -w;
        auto &[i, j] = ij;
        if (taken[i][j]) {
            continue;
        }
        max_cost = max(w, max_cost);
        process(i, j, m, n);
    }
    return max_cost;
}

int main(int argc, char *argv[]) {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> h[i][j];
            taken[i][j] = false;
        }
    }

    cout << prim(0, 0, m, n) << endl;
    return 0;
}

