#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int get_mex(vector<vector<int>> &m, int n, int i, int j, vector<int> &mex_vec) {
    int curr;
    for (int t = 0; t < i; t++) {
        curr = m[t][j];
        mex_vec[curr] = 1;
    }
    for (int t = 0; t < j; t++) {
        curr = m[i][t];
        mex_vec[curr] = 1;
    }
    int ans = 0;
    while (ans < mex_vec.size() && mex_vec[ans] == 1) ans++;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<int> mex_vec(n*n, 0);
    
    for (int i = 0; i < n; i++) m[i][0] = i;
    for (int j = 0; j < n; j++) m[0][j] = j;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            vector<int> temp_mex(mex_vec);
            m[i][j] = get_mex(m, n, i, j, temp_mex);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << m[i][j] << " ";
        cout << endl;
    }

    return 0;
}
