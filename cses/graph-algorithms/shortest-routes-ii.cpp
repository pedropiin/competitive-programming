#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e15

void floyd_warshall(vector<vector<ll>> &dist, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(n);
    for (int i = 0; i < n; i++) {
        dist[i].assign(n, INF);
        dist[i][i] = 0;
    }

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (dist[a - 1][b - 1] < c) {
            continue;
        }
        dist[a - 1][b - 1] = c;
        dist[b - 1][a - 1] = c;
    }

    floyd_warshall(dist, n);

    int s, d;
    for (int i = 0; i < q;  i++) {
        cin >> s >> d;
        if (dist[s - 1][d - 1] < INF) {
            cout << dist[s - 1][d - 1] << endl;
        } else {
            cout << -1 << endl;
        }
    }


    return 0;
}