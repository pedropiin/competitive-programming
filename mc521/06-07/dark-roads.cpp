#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> taken;
priority_queue<pair<int, int>> pq;

void process(int node, vector<vector<pair<int, int>>> &adj) {
    taken[node] = 1;
    for (int j = 0; j < (int)adj[node].size(); j++) {
        pair<int, int> v = adj[node][j];
        if (!taken[v.first]) {
            pq.push(pair<int, int>(-v.second, -v.first));
        }
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n; // nodes and edges
    cin >> m >> n;
    while (m != 0 && n != 0) {
        vector<vector<pair<int, int>>> adj(m);
        int x, y, z;
        int og_cost = 0;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            adj[x].push_back(make_pair(y, z));
            adj[y].push_back(make_pair(x, z));
            og_cost += z;
        }

        pq = priority_queue<pair<int, int>>();
        taken.assign(m, 0);
        process(0, adj);
        int opt_cost = 0;
        int node, w;
        while (!pq.empty()) {
            pair<int, int> front = pq.top();
            pq.pop();
            node = -front.second;
            w = -front.first;
            if (!taken[node]) {
                opt_cost += w;
                process(node, adj);
            }
        }
        cout << og_cost - opt_cost << endl;

        cin >> m >> n;
    }

    return 0;
}