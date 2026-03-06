#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dfs(vector<vector<int>> &adj, vector<int> &visited, vector<int> &parent, vector<int> &curr_path, int u) {
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = 1;
            parent[v] = u;
            curr_path[v] = 1;
            if (dfs(adj, visited, parent, curr_path, v)) return 1;
            curr_path[v] = 0;
        } else {
            if (curr_path[v]) {
                vector<int> cycle; cycle.push_back(v);
                int curr = u;
                while (curr != v && curr != -1) {
                    cycle.push_back(curr);
                    curr = parent[curr];
                }
                cycle.push_back(curr);

                cout << cycle.size() << endl;
                for (int i = cycle.size()-1; i >= 0; i--) cout << cycle[i]+1 << " ";
                cout << endl;
                
                return 1;
            }
        }
    }
    return 0;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    vector<int> visited(n, 0);
    vector<int> parent(n, -1);
    vector<int> curr_path(n, 0);
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        curr_path[i] = 1;
        if (dfs(adj, visited, parent, curr_path, i)) return;
        curr_path[i] = 0;
    }

    cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--) solve();

    return 0;
}
