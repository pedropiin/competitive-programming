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

    return 0;
}