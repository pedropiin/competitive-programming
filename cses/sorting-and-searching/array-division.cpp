#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    int mx = 0;
    ll tot_sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
        tot_sm += (ll)v[i];
    }

    ll l = (ll)mx, r = tot_sm, m, ans = tot_sm;
    while (l <= r) {
        m = l + (r-l)/2;

        ll cnt = 0, temp_sm = 0;
        for (int i = 0; i < n; i++) {
            temp_sm += (ll)v[i];
            if (temp_sm > m) {
                cnt++;
                temp_sm = v[i];
            }
        }
        if (temp_sm <= m) cnt++;
    
        if (cnt <= k) {
            ans = min(ans, m);
            r = m-1;
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

