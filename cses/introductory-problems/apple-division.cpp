#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll r = 1 << n;
    ll ans = LLONG_MAX;
    for (int i = 0; i < r; i++) {
        ll sum1 = 0, sum2 = 0;
        for (int bit = 0; bit < n; bit++) {
            if (i & (1 << bit)) {
                sum1 += v[bit];
            } else {
                sum2 += v[bit];
            }
        }
        ans = min(ans, abs(sum2 - sum1));
    }

    cout << ans << endl;


    return 0;
}