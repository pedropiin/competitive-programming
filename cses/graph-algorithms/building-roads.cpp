#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX_VERT 100005

vector<int> color(MAX_VERT, 0);

void dfs(vector<vector<int>> &adj, int v) {
    int a;
    color[v] = 1;
    for (int i = 0; i < adj[v].size(); i++) {
        a = adj[v][i];
        if (color[a] == 0) {
            dfs(adj, a);
        }
    }
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            ans.push_back(i);
            dfs(adj, i);
        }
    }

    cout << ans.size() - 1 << endl;
    for (int i = 0; i < (ans.size() - 1); i++) {
        cout << ans[i] + 1 << " " << ans[i + 1] + 1 << endl;
    }

    return 0;
}