#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long ll;

void matmul(vector<vector<int>> &a, vector<vector<int>> &b, vector<vector<int>> &result, int m) {
    vector<vector<int>> temp(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                temp[i][j] += ((a[i][k] % MOD) * 1ll * (b[k][j] % MOD)) % MOD;
                temp[i][j] %= MOD;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = temp[i][j];
        }
    }
}

void matexpo(vector<vector<int>> &mat, vector<vector<int>> &result, int m, ll n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = (i == j);
        }
    }
    
    while (n > 0) {
        if (n % 2 == 0) {
            matmul(mat, mat, mat, m);
            n /= 2;
        } else {
            matmul(mat, result, result, m);
            n--;
        }
    }
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<vector<int>> mat {{1, 1}, {1, 0}};
    vector<vector<int>> res(2, vector<int>(2));
    matexpo(mat, res, 2, n);

    cout << res[0][1] << endl;

    return 0;
}