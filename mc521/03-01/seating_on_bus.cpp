#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < (2 * n); i++) {
        if ((i + 2 * n) < m) {
            cout << (i + 2 * n) + 1 << ' ';
        }
        if (i < m) {
            cout << i + 1 << ' ';
        }
    }
    cout << endl;

    return 0;
}