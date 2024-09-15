#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * (b / gcd(a, b));
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<int> mods(n);
    for (int i = 0; i < n; i++) {
        cin >> mods[i];
        if (mods[i] == k) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    ll gen_lcm = 1;
    for (int i = 0; i < n; i++) {
        gen_lcm = lcm(gen_lcm, mods[i]) % k;
        if (gen_lcm % k == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}