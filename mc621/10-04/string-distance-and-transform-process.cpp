#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9

vector<int> dist;
vector<int> pred;

void dijkstra(int s, int n, vector<vector<pair<int, int>>> &adj) {
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

    string s1, s2;
    while (cin >> s1) {
        cin >> s2;

        int n1 = s1.size();
        int n2 = s2.size();

        int lines = (n1 + 1);
        int cols = (n2 + 1);
        vector<vector<pair<int, int>>> adj((lines) * (cols), vector<pair<int, int>>());

        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == (lines - 1) && j == (cols - 1)) {
                    // final node. It doesn't have any edges. Therefore, no need for initialization.
                    continue;
                } else {
                    // common nodes
                    if ((j + 1) < cols && (i + 1) < lines) {
                        // not a corner case of the graph;
                        // adding horizontal edge with weight = 1
                        adj[i * cols + j].push_back(make_pair((i * cols + j + 1), 1));  

                        //adding vertcal edge with weight = 1;
                        adj[i * cols + j].push_back(make_pair(((i + 1) * cols + j), 1));

                        // adding diagonal edge with conditional weigh;
                        adj[i * cols + j].push_back(make_pair(((i + 1) * cols + j + 1), s1[i] == s2[j] ? 0 : 1));
                    } else if ((i + 1) >= lines) {
                        // last line of the matrix. Therefore, only horizontal lines
                        adj[i * cols + j].push_back(make_pair((cols * i + j + 1), 1));
                    } else if ((j + 1) >= cols) {
                        // last column of the matrix. Therefore, only vertical lines.
                        adj[i * cols + j].push_back(make_pair((cols * (i + 1) + j), 1));
                    }
                }
            }
        }

        dijkstra(0, (lines * cols), adj);
        cout << dist[lines * cols - 1] << endl;

        // print path
        stack<pair<int, int>> seq;
        int target = lines * cols - 1;
        while (pred[target] != -1) {
            seq.push(make_pair(target, pred[target]));
            target = pred[target];
        }


        int count = 0;
        int i_pred, j_pred, i_move, j_move;
        int removes = 0, inserts = 0;
        while (!seq.empty()) {
            pair<int, int> temp = seq.top();
            i_pred = temp.second / cols;
            j_pred = temp.second % cols;
            i_move = temp.first / cols;
            j_move = temp.first % cols;

            if ((i_move - i_pred) == 1 && (j_move - j_pred) == 1) {
                // moved diagonally
                if (adj[i_pred * cols + j_pred][2].second == 1) {
                    cout << ++count << " Replace " << (i_move - removes + inserts) << ',' << s2[j_move - 1] << endl;
                } 
            } else if ((i_move - i_pred) == 1) {
                // moved vertically
                cout << ++count << " Delete " << (i_move - removes + inserts) << endl;
                removes++;
            } else if ((j_move - j_pred) == 1) {
                cout << ++count << " Insert " << (i_move + 1 - removes + inserts) << ',' << s2[j_move - 1] << endl;
                inserts++;
            }
            seq.pop();
        }
        cout << endl;

        dist.clear();
        pred.clear();
        adj.clear();
    }

    return 0;
}