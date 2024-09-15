#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * (b / gcd(a, b));
}

ll sieving_ctr(vector<int> mods, vector<int> ints) {
    ll max_value = mods[0] * mods[1] + 1;

    ll sum_factor = 1;
    ll sol = ints[0];
    for (int i = 0; i < 1; i++) {
        sum_factor *= mods[i];
        while (sol % mods[i + 1] != ints[i + 1]) {
            sol += sum_factor;
            if (sol > max_value) {
                return -1;
            }
        }
    }
    return sol;
}


int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, n, b, m;
        cin >> a >> n >> b >> m;
        vector<int> mods(2);
        vector<int> ints(2);

        if (n < m) {
            mods[0] = n;
            mods[1] = m;
            ints[0] = a;
            ints[1] = b;            
        } else {
            mods[0] = m;
            mods[1] = n;
            ints[0] = b;
            ints[1] = a; 
        }

        ll x = sieving_ctr(mods, ints);
        if (x != -1) {
            ll k = lcm(n, m);
            cout << (x % k) << " " << k << endl;
        } else {
            cout << "no solution" << endl;
        }
    }

    return 0;
}