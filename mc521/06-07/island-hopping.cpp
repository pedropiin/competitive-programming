#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> taken;
priority_queue<pair<float, int>> pq;

struct Island {
    int n;
    float x, y;
};

float calc_dist(float x1, float y1, float x2, float y2) {
    float diff_x = x1 - x2;
    float diff_y = y1 - y2;
    float dist = sqrt(pow(diff_x, 2) + pow(diff_y, 2));
    return dist;
}

void process(int node, vector<vector<pair<Island, float>>> &adj) {
    taken[node] = 1;
    for (int j = 1; j < (int)adj[node].size(); j++) {
        pair<Island, float> v = adj[node][j];
        if (!taken[v.first.n]) {
            pq.push(pair<float, int>(-v.second, -v.first.n)); // guardando na pq apenas dist e indice
        }
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    cin >> a;
    for (int _ = 0; _ < a; _++) {
        int m;
        cin >> m;
        // Each element of the vector stores the 'j' and the 
        // distance of node i to node j
        vector<vector<pair<Island, float>>> adj(m);

        // Receiving islands and calculating distances
        for (int i = 0; i < m; i++) {
            float xi, yi;
            cin >> xi >> yi;
            Island new_island = {i, xi, yi};
            adj[i].push_back(make_pair(new_island, 0));
            for (int j = 0; j < i; j++) {
                pair<Island, float> island_it = adj[j][0];
                float dist = calc_dist(xi, yi, island_it.first.x, island_it.first.y);
                Island new_node = {j, island_it.first.x, island_it.first.y};
                adj[i].push_back(make_pair(new_node, dist));
                adj[j].push_back(make_pair(new_island, dist));
            }
        }

        taken.assign(m, 0);
        pq = priority_queue<pair<float, int>>(); // Resetting the priority queue
        process(0, adj);
        float cost = 0;
        while (!pq.empty()) {
            pair<float, int> front = pq.top();
            pq.pop();
            int idx_node = -front.second;
            float dist = -front.first;
            
            if (!taken[idx_node]) {
                cost += dist;
                process(idx_node, adj);
            }
        }
        cout << fixed;
        cout << setprecision(3);
        cout << cost << endl;
    }

    return 0;
}