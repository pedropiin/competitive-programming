#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans(n, 0);
    vector<int> visited(n, 0);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        q.push({i, 0});
        ans[i] = 0;

        while (!q.empty()) {
            int u = q.front().first, team = q.front().second;
            int new_team = team ^ 1;
            q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    ans[v] = new_team;
                    q.push({v, new_team});
                } else {
                    if (ans[v] == ans[u]) {
                        cout << "IMPOSSIBLE" << endl;
                        return;
                    }
                }
            }
        }
    }

    for (int elem : ans) cout << elem+1 << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--) solve();

    return 0;
}
