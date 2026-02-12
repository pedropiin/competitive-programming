#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll true_mod(ll x, ll mod) {
    if (x >= 0) return x % mod;
    else return ((x%mod) + mod) % mod;
}

void solve() {
    ll n; cin >> n;
    vector<int> v(n);
    vector<ll> pref(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pref[i+1] = true_mod(pref[i] + (ll)v[i], n);
    }

    unordered_map<int, int> m;
    ll ans = 0;
    for (int i = 0; i < n+1; i++) {
        ans += (ll)m[pref[i]];
        m[pref[i]]++;
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
