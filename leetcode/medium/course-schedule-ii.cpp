#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int n = prerequisites.size();
    vector<vector<int>> adj(numCourses, vector<int>());
    for (int i = 0; i < n; i++) {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    vector<int> deg(numCourses, 0);
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        for (int v : adj[i]) deg[v]++;
    }
    for (int i = 0; i < numCourses; i++) {
        if (deg[i] == 0) q.push(i);
    }

    vector<int> ans;
    if (q.empty()) return ans;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        ans.push_back(curr);
        for (int v : adj[curr]) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    } 
    if (ans.size() != numCourses) return vector<int>();
    return ans;     
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int numCourses; cin >> numCourses;
    int n; cin >> n;
    vector<vector<int>> prerequisites(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) cin >> prerequisites[i][0] >> prerequisites[i][1];

    cout << findOrder(numCourses, prerequisites) << endl;

    return 0;
}
