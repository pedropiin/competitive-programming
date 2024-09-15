#include <bits/stdc++.h>

#define MAX 1005

using namespace std;

typedef long long ll;



vector<vector<int>> adj(MAX);
vector<int> cor;
vector<int> resp(MAX);
int cnt = 0;

void dfs(int v) {
    int a;
    cor[v] = 1;
    for (int i = 0; i < adj[v].size(); i++) {
        a = adj[v][i];
        if (cor[a] == 0) {
            dfs(a);
        } else if (cor[a] == 1) {
            resp[cnt++] = a;
        }
    }
}


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;
        adj[i].push_back(p - 1);
        cor.push_back(i);
        cor[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
        }
    }

    int t = 0;
    for (int i = 0; i < n; i++) {
        dfs(i);
        for (int i = 0; i < n; i++) {
            cor[i] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << resp[i] + 1 << ' ';
    }
    cout << endl;

    return 0; 
}