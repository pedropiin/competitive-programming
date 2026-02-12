#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, t; cin >> n >> t;
    vector<int> v(n);
    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mn = min(mn, v[i]);
    }

    ll l = 0, r = (ll)mn*(ll)t, m;
    ll ans = r;
    while (l <= r) {
        m = l + (r-l)/2;
        ll sm = 0;
        for (int i = 0; i < n; i++) {
            sm += (ll)(m/v[i]);
        }

        if (sm >= t) {
            r = m-1;
            ans = min(ans, m);
        } else {
            l = m+1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--) solve();

    return 0;
}
