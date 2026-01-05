#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    int a, b;
    vector<vector<int>> adj(n, vector<int>());
    vector<int> deg(n, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[--a].push_back(--b);
        deg[b]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) q.push(i);
    }

    vector<int> ans;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        ans.push_back(curr);

        for (int v : adj[curr]) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }

    if (ans.size() != n) cout << "IMPOSSIBLE" << endl;
    else {
        for (int elem : ans) cout << elem+1 << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
