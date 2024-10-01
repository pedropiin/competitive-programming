#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e15

vector<ll> dist;
vector<ll> pred;

void dijkstra(int s, int n, vector<vector<pair<ll, ll>>> &adj) {
	dist.assign(n, INF);
	pred.assign(n, -1);
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

	dist[s] = 0;
	pq.push(make_pair(dist[s], s));

	while (!pq.empty()) {
		pair<ll, ll> front = pq.top(); pq.pop();
		ll d = front.first, u = front.second;
		if (d > dist[u]) {
			continue;
		}
		for (ll j = 0; j < adj[u].size(); j++) {
			pair<ll, ll> v = adj[u][j];
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pred[v.first] = u;
				pq.push(make_pair(dist[v.first], v.first));
			}
		}
	}
}


int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	vector<vector<pair<ll, ll>>> adj(n);
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a - 1].push_back(make_pair(b - 1, c));
	}

	dijkstra(0, n, adj);

	for (int i = 0; i < n; i++) {
		cout << dist[i] << " ";
	}
	cout << endl;

	return 0;
}
