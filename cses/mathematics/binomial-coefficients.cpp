#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int maxn = 1000005;

ll mod_inv(int a) {
    if (a <= 1) {
        return 1;
    } 
    return mod - ((mod / a) * mod_inv(mod % a)) % mod;
}

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<ll> fact(maxn);
    fact[0] = 1; fact[1] = 1;
    for (int i = 2; i < maxn; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << (fact[a] * mod_inv(fact[b]) % mod) * mod_inv(fact[a-b]) % mod << endl;
    }

    return 0;
}