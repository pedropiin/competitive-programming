#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9

vector<vector<pair<int, int>>> adj;

int bellman_ford(int s, int n) {
    vector<int> dist(n, INF);
    vector<int> pred(n, -1);
    dist[s] = 0;

    for (int i = 0; i < (n - 1); i++) {
        for (int u = 0; u < n; u++) {
            for (int j = 0; j < adj[u].size(); j++) {
                pair<int, int> v = adj[u][j];
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pred[v.first] = u;
                }
            }
        }
    }

    int ciclo_negativo = 0;
    for (int u = 0; u < n; u++) {
        for (int j = 0; j < adj[u].size(); j++) {
            pair<int, int> v = adj[u][j];
            if (dist[v.first] > dist[u] + v.second) {
                ciclo_negativo = 1;
            }
        }
    }

    return ciclo_negativo;
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}