#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            ans ^= (x % 4);
        }

        if (ans == 0) {
            cout << "second" << endl;
        } else {
            cout << "first" << endl;
        }
    }

    return 0;
}