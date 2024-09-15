#define MAX 20001
#define INF 1e9

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> dist;
vector<int> pred;

void dijkstra(int s, int n, vector<vector<pair<int, int>>> adj) {
    dist.assign(n, INF);
    pred.assign(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push(make_pair(dist[s], s));

    while (!pq.empty()) {
        pair<int, int> front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) {
            continue;
        }
        for (int j = 0; j < adj[u].size(); j++) {
            pair<int, int> v = adj[u][j];
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pred[v.first] = u;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }
}


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    for (int num_teste = 0; num_teste < q; num_teste++) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vector<vector<pair<int, int>>> adj(n);
        int v1, v2, w;
        for (int i = 0; i < m; i++) {
            cin >> v1 >> v2 >> w;
            adj[v1].push_back(make_pair(v2, w));
            adj[v2].push_back(make_pair(v1, w));
        }
        dijkstra(s, n, adj);
        cout << "Case #" << (num_teste + 1) << ": ";
        if (dist[t] >= INF) {
            cout << "unreachable";
        } else {
            cout << dist[t];
        }
        cout << endl;
    }

    return 0;   
}