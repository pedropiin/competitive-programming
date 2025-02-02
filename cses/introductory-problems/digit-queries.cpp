#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<ull> bound;
    bound.push_back(9);
    for (int i = 1; i <= 18; i++) {
        ull temp = 9 * (i + 1) * pow(10, i);
        bound.push_back(temp + bound[i - 1]);
    }

    int q;
    cin >> q;
    ull k;
    for (int _ = 0; _ < q; _++) {
        cin >> k;

        int idx, n;
        for (int i = 0; i < bound.size(); i++) {
            if (bound[i] >= k) {
                idx = i;
                n = i + 1;
                break;
            }
        }

        ull base = (idx >= 1) ? bound[idx - 1] : 0;
        ll diff = k - base;
        ll p = binpow(10, idx);
        ll number = binpow(10, idx) + (diff - 1) / n;
        ull nth = (diff - 1) % n; // zero-indexed position of the desired digit relative to its number

        cout << (number / binpow(10, n - nth - 1)) % 10 << endl;
    }

    return 0;
}
