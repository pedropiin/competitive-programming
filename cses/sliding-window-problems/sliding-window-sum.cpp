#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, k; cin >> n >> k;
    ll xprev, a, b, c; cin >> xprev >> a >> b >> c;

    ll first = xprev;
    ll x, summ = first;
    for (int i = 1; i < k; i++) {
        x = (ll)((ll)(a*xprev) + b) % c;
        summ += x;
        xprev = x;
    }
    ll ans = summ;
    for (int i = k; i < n; i++) {
        x = (ll)((ll)(a*xprev) + b) % c;
        summ += x;
        xprev = x;

        summ -= first;
        first = (ll)((ll)(a*first) + b) % c;
        ans ^= summ;
    }

    cout << ans << endl;

    return 0;
}
