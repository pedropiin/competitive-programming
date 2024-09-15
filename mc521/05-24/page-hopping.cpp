#include <bits/stdc++.h>

#define MAX_SIZE 100
#define INF 1e9

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a0, b0, a, b;
    cin >> a0 >> b0;

    int count = 0;
    while (a0 != 0 && b0 != 0) {
        set<int> s;
        s.insert(a0);
        s.insert(b0);

        int dist[MAX_SIZE][MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                dist[i][j] = INF;
            }
            dist[i][i] = 0;
        }

        dist[a0 - 1][b0 - 1] = 1;
        cin >> a >> b;

        while (a != 0 && b != 0) {
            s.insert(a);
            s.insert(b);
            dist[a - 1][b - 1] = 1;
            cin >> a >> b;
        }

        int num_nodes = s.size();
        int max_node = *(s.rbegin());
        for (int k = 0; k < max_node; k++) {
            for (int i = 0; i < max_node; i++) {
                for (int j = 0; j < max_node; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < max_node; i++) {
            for (int j = 0; j < max_node; j++) {
                if (dist[i][j] != INF) {
                    sum += dist[i][j];
                }
            }
        }

        int comb = num_nodes * (num_nodes - 1);
        float avg = (float)sum / comb;
        cout << fixed;
        cout << setprecision(3);
        cout << "Case " << ++count << ": average length between pages = " << avg << " clicks" << endl;

        cin >> a0 >> b0;
    }

    return 0;
}