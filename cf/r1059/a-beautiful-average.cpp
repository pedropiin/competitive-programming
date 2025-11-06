#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n; 
    cin >> n;

    int ans = 0;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        ans = max(ans, t);
    }
    cout << ans << endl;
}

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}