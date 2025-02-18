#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v[i] = {x, y};
    }

    sort(v.begin(), v.end());
    ll time = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        time += v[i].first;
        ans += (v[i].second - time);
    }

    cout << ans << endl;

    return 0;
}