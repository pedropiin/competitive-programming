#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

typedef long long ll;

int bfs(int s, int t, vector<int> &parent, vector<vector<int>> &adj, vector<vector<int>> &capacity) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t, int n, vector<vector<int>> &adj, vector<vector<int>> &capacity) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent, adj, capacity)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int get_flow_edges(int s, int t, vector<vector<int>> &capacity, vector<vector<int>> &og_capacity) {
    int count = 0;
    for (int i = 0; i < capacity.size(); i++) {
        for (int j = 0; j < capacity[i].size(); j++) {
            if (og_capacity[i][j] > 0 && capacity[i][j] < og_capacity[i][j]) {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<int>> adj(n);
    vector<vector<int>> capacity(n, vector<int>(n, 0));
    vector<vector<int>> og_capacity(n, vector<int>(n, 0));

    int u, v, c;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        adj[u].push_back(v);
        capacity[u][v] = c;
        og_capacity[u][v] = c;
    }

    int max_flow = maxflow(s, t, n, adj, capacity);
    int count = get_flow_edges(s, t, capacity, og_capacity);
    
    cout << n << " " << max_flow << " " << count << endl;
    for (int i = 0; i < capacity.size(); i++) {
        for (int j = 0; j < capacity[i].size(); j++) {
            if (og_capacity[i][j] > 0 && capacity[i][j] < og_capacity[i][j]) {
                cout << i << " " << j << " " << og_capacity[i][j] - capacity[i][j] << endl;
            }
        }
    }

    return 0;
}