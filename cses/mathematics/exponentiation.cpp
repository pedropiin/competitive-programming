#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    ll a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << binpow(a, b) << endl;
    }

    return 0;
}