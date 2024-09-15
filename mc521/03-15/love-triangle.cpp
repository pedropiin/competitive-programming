#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int gosta[n], gostado[n];
    for (int i = 0; i < n; i++) {
        gosta[i] = -1;
        gostado[i] = -1;
    }

    int num, existe = 0;
    for (int i = 0; i < n; i++) {
        cin >> num;
        gosta[i] = num;
        gostado[num - 1] = i + 1;
        if (gosta[num - 1] != -1) {
            if (gosta[num - 1] == gostado[i]) {
                cout << "YES" << endl;
                existe = 1;
                break;
            }
        } else {
            continue;
        }
    }

    if (existe == 0) {
        cout << "NO" << endl;
    }

    return 0;
}