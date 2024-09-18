#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007
#define P 1783

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.length();

    // Based on Geeks for Geeks explanation on Rolling Hash
    vector<ll> pow(n);
    pow[0] = 1;
    for (int i = 1; i < n; i++) {
        pow[i] = (pow[i-1] * P) % MOD;
    }

    size_t lhash = 0;
    size_t rhash = 0;
    for (int i = 0; i < (n - 1); i++) {
        lhash = (lhash + s[i] * pow[i]) % MOD;
        rhash = (rhash * P + s[i - n - 1]) % MOD;

        if (lhash == rhash) {
            cout << (i + 1) << " ";
        }
    }

    cout << endl;

    return 0;
}