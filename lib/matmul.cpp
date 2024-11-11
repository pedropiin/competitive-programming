#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

void matmul(vector<vector<int>> &a, vector<vector<int>> &b, vector<vector<int>> &result, int m) {
    vector<vector<int>> temp(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                temp[i][j] += ((a[i][k] % mod) * 1ll * (b[k][j] % mod)) % mod;
                temp[i][j] %= mod;
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
    cout.tie(0);

    

    return 0;
}