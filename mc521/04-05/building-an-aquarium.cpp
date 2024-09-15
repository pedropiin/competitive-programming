#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int valid_height(vector<int> &a, int n, int x, int test_height) {
    ll w = 0;
    for (int i = 0; i < n; i++) {
        if (test_height > a[i]) {
            w += test_height - a[i];
        }
    }

    if (w <= x) {
        return 1;
    }
    return 0;
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll low_idx = 1;
        ll high_idx = 2e9;
        ll mid = 0;
        ll ans = 0;

        while (low_idx <= high_idx) {
            mid = (low_idx + high_idx) / 2;
            if (valid_height(a, n, x, mid)) {
                ans = mid;
                low_idx = mid + 1;
            } else {
                high_idx = mid - 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}