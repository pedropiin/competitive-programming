#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void push_mono_dq(deque<ll> &dq, ll n) {
    while (!dq.empty() && dq.back() > n) dq.pop_back();
    dq.push_back(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, k; cin >> n >> k;
    ll xprev, a, b, c; cin >> xprev >> a >> b >> c;

    deque<ll> dq; dq.push_back(xprev);
    deque<ll> nums; nums.push_back(xprev);
    ll x;
    for (int i = 1; i < k; i++) {
        x = (ll)((ll)a*xprev + b) % c;
        push_mono_dq(dq, x);
        nums.push_back(x);
        xprev = x;
    }
    ll ans = dq.front();
    for (int i = k; i < n; i++) {
        x = (ll)((ll)a*xprev + b) % c;
        nums.push_back(x);
        push_mono_dq(dq, x);
        if (!dq.empty() && nums.front() == dq.front()) dq.pop_front();
        nums.pop_front();
        ans ^= dq.front();
        xprev = x;
    }
    cout << ans << endl;

    return 0;
}
