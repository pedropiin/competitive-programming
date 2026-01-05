#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void get_divs(unordered_set<int> &divs, int n) {
    int cl = ceil((double)sqrt(n));
    for (int i = 2; i <= cl; i++) {
        if (n % i == 0) {
            divs.insert(i);
            divs.insert(n/i);
        }
    }
}

int build(vector<ll> &v, int i) {
    if (v[i] != 0) return v[i];

    if (i % 2 == 0) {
        v[i] = build(v, i/2) + 2;
        return v[i];
    }
    else {
        unordered_set<int> divs;
        get_divs(divs, i);
        if (divs.size() == 0) {
            v[i] = i;
            return i; // prime
        }

        ll ans = LONG_LONG_MAX;
        for (auto div : divs) {
            ll cps = i / div;
            ans = min(ans, (ll)((ll)build(v, div) + cps));
        }
        v[i] = ans;
        return v[i];
    }
}

int minSteps(int n) {
    vector<ll> v(1001, 0);
    v[0] = -1; v[1] = 0; v[2] = 2;
    for (int i = 3; i <= n; i++) {
        build(v, i);
    }
    return v[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    cout << minSteps(n) << endl;
    
    return 0;
}
