#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, num;
    while(cin >> n) {
        vector<int> v(n);
        vector<int> f(n - 1);

        for (int i = 0; i < (n - 1); i++) {
            f[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int dif;
        for (int i = 0; i < (n - 1); i++) {
            dif = abs(v[i] - v[i + 1]);
            if (dif >= n || dif == 0) {
                cout << "Not jolly" << endl;
                break;
            } 
            if (f[dif - 1] == 0) {
                f[dif - 1] = 1;
                continue;
            } else if (f[dif - 1] == 1) {
                cout << "Not jolly" << endl;
                break;
                // continue;
            }
        }

        int completo = 1;
        for (int i = 0; i < (n - 1); i++) {
            if (f[i] == 0) {
                completo = 0;
                break;
            }
        }

        if (completo == 1) {
            cout << "Jolly" << endl;;
        }
    }
    return 0;
}