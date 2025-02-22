#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    map<int, int> m;
    int l = 0, r = 0;
    int t, max_count = 0, count = 0;
    while (r < n && l <= r) {
        t = v[r];
        m[t]++;
        count++;
        while (m[t] > 1) {
            m[v[l++]]--;
            count--;
        }
        r++;
        max_count = max(max_count, count);
    }

    cout << max_count << endl;

    return 0;
}