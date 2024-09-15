#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    vector<int> a(n - 1);
    for (int i = 0; i < (n - 1); i++) {
        cin >> a[i];
    }

    int analysis = 0;
    int possible = 0;

    while ((analysis + 1) < t) {
        analysis += a[analysis];
        if ((analysis + 1) == t) {
            possible = 1;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}