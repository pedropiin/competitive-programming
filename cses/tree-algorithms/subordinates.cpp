#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> color(maxn);
vector<int> parent(maxn);
vector<int> ans(maxn);

void dfs(vector<vector<int>> &adj, int v) {
    int a;
    color[v] = 1;
    for (int i = 0; i < adj[v].size(); i++) {
        a = adj[v][i];
        if (color[a] == 0) {
            dfs(adj, a);
        }
    }
    if (v != 0) {
        ans[parent[v]] += (ans[v] + 1);
    }
}

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    int t;
    for (int i = 0; i < (n - 1); i++) {
        cin >> t;
        adj[t - 1].push_back(i + 1);
        parent[i + 1] = t - 1;
    }

    dfs(adj, 0);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }


    return 0;
}