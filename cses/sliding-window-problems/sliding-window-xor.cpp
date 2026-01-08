#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, k; cin >> n >> k;
    ll xprev, a, b, c; cin >> xprev >> a >> b >> c;

    ll x, first = xprev, xr = xprev;
    for (int i = 1; i < k; i++) {
        x = (ll)((ll)a*xprev + b) % c;
        xr = xr ^ x;
        xprev = x;
    }
    ll ans = xr;
    for (int i = k; i < n; i++) {
        x = (ll)((ll)a*xprev + b) % c;
        xr ^= x;
        xr ^= first;
        first = (ll)((ll)a*first + b) % c;
        ans ^= xr;
        xprev = x;
    }

    cout << ans << endl;

    return 0;
}
