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

void matexpo(vector<vector<int>> &mat, vector<vector<int>> &result, int m, int n) {
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

    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> mat(m, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }

        vector<vector<int>> result(m, vector<int>(m));

        matexpo(mat, result, m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cout << result[i][j] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}