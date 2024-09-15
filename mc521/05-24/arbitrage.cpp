#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

typedef long long ll;

bool arbitrage(int v, vector<vector<double>> &dist) {
    for (int k = 0; k < v; k++) {
        for (int u = 0; u < v; u++) {
            for (int t = 0; t < v; t++) {
                double cand = dist[u][k] * dist[k][t];
                if (cand < dist[u][t]) {
                    dist[u][t] = cand;
                }
            }
        }
    }
    for (int u = 0; u < v; u++) {
        if (dist[u][u] < 1) {
            return true;
        }
    }
    return false;
}

int main(int charc, char *argv[]) {
    int v, e;
    while ((cin >> v) && v) {
        vector<vector<double>> dist(v, vector<double>(v, INF));
        map<string, int> id;
        for (int i = 0; i < v; i++) {
            string name;
            cin >> name;
            id[name] = i;
            dist[i][i] = 1.0;
        }

        cin >> e;
        while (e--) {
            string s, t;
            unsigned num, denom;
            cin >> s >> t;
            scanf("%u:%u\n", &num, &denom);
            dist[id[s]][id[t]] = (num * 1.0) / denom;
        }

        if (arbitrage(v, dist)) {
            cout << "Arbitrage" << endl;
        } else {
            cout << "Ok" << endl;
        }
    }

    return 0;
}
