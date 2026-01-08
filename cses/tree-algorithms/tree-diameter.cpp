#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int bfs(vector<vector<int>> &adj, vector<bool> &visited, int src, int &ans) {
    queue<pair<int, int>> q; q.push({src, 0});
    visited[src] = true;
    int u, cnt;
    int mx_cnt = 0, ret = src;
    while (!q.empty()) {
        u = q.front().first;
        cnt = q.front().second;
        q.pop();
        if (cnt > mx_cnt) {
            mx_cnt = cnt;
            ret = u;
        }
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) q.push({v, cnt+1});
        }
    }
    ans = mx_cnt;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    int u, v;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    int ans = 0;
    int deep = bfs(adj, visited, 0, ans);
    fill(visited.begin(), visited.end(), false);
    bfs(adj, visited, deep, ans);
    cout << ans << endl;

    return 0;
}
