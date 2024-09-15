#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int p, r, count = 0;
    cin >> p >> r;

    while (p != 0 && r != 0) {
        int dist[p][p];
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                dist[i][j] = INF;
            }
            dist[i][i] = 0;
        }

        map<string, int> users;
        map<string, int>::iterator it;
        string name;
        int idx1, idx2, users_count = 0;
        for (int i = 0; i < r; i++) {
            cin >> name;
            it = users.find(name);
            // usuário já foi adicionado
            if (it != users.end()) {
                idx1 = it->second;
            } else {
                idx1 = users_count;
                users[name] = users_count++;
            }
            // encontrando segundo usuário
            cin >> name;
            it = users.find(name);
            if (it != users.end()) {
                idx2 = it->second;
            } else {
                idx2 = users_count;
                users[name] = users_count++;
            }

            dist[idx1][idx2] = 1;
            dist[idx2][idx1] = 1;
        }

        int max_dist = 0;
        for (int k = 0; k < p; k++) {
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < p; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int connected = 1;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                if (dist[i][j] >= INF) {
                    connected = 0;
                    break;
                } else {
                    if (dist[i][j] > max_dist) {
                        max_dist = dist[i][j];
                    }
                }
            }
            if (!connected) {
                break;
            }
        }

        cout << "Network " << ++count << ": ";
        if (connected) {
            cout << max_dist << endl;
        } else {
            cout << "DISCONNECTED" << endl;
        }
        cout << '\n';
        
        cin >> p >> r;
    }


    return 0;
}