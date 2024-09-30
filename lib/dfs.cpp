#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> adj(MAX);
vector<int> color;
vector<int> resp(MAX);
int cnt = 0;

void dfs(int v) {
    int a;
    color[v] = 1;
    for (int i = 0; i < adj[v].size(); i++) {
        a = adj[v][i];
        if (color[a] == 0) {
            dfs(a);
        } else if (color[a] == 1) {
            resp[cnt++] = a;
        }
    }
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}