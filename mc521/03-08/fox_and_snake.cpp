#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, ponto = 1;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (((i) % 2) == 1) {
                cout << '#';
            } else {
                if (ponto == 1) {
                    if (j != m) {
                        cout << '.';
                    } else {
                        cout << '#';
                    }
                } else {
                    if (j == 1) {
                        cout << '#';
                    } else {
                        cout << '.';
                    }
                }
            }
        }
        if ((i + 1) % 4 == 0) {
            ponto = 0;
        } else {
            ponto = 1;
        }
        cout << endl;
    }

    return 0;
}