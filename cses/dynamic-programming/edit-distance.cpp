#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9

vector<int> dist;

void dijkstra(int s, int n, vector<vector<pair<int, int>>> &adj) {
	dist.assign(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});

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
                // pred[v.first] = u;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	int n1 = s1.size(), n2 = s2.size();

	int lines = (n1 + 1);
	int cols = (n2 + 1);
	vector<vector<pair<int, int>>> adj((lines * cols + 100));

	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == (lines - 1) && j == (cols - 1)) {
				// final node. It doesn't have any edges. Therefore, no need for initialization
				continue;
			} else {
				// common nodes
				if ((j + 1) < cols && (i + 1) < lines) {
					// not a corner case of the graph;
					// adding a horizontal edge with weight = 1
					adj[i * cols + j].push_back(make_pair((i * cols + j + 1), 1));

					// adding vertical edge with weight = 1;
					adj[i * cols + j].push_back(make_pair(((i + 1) * cols + j), 1));

					// adding diagonal edge with conditional weight;
					adj[i * cols + j].push_back(make_pair(((i + 1) * cols + j + 1), s1[i] == s2[j] ? 0 : 1));
				} else if ((i + 1) >= lines) {
					// last line of the matrix. Therefore, only horizontal lines
					adj[i * cols + j].push_back(make_pair((cols * i + j + 1), 1));
				} else if ((j + 1) >= cols) {
					// last column of the matrix. Therefore, only vertical lines
					adj[i * cols + j].push_back(make_pair((cols * (i + 1) + j), 1));
				}
			}
		}
	}

	dijkstra(0, (lines * cols), adj);
	cout << dist[lines * cols - 1] << endl;
	
	return 0;
}
