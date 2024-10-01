#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9

vector<vector<pair<int, int>>> adj;
vector<int> dist;
vector<int> pred;

void dijkstra(int s, int n) {
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


int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
