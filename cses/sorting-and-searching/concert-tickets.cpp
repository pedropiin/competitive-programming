#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    multiset<int, greater<int>> s;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        s.insert(t);
    }

    for (int i = 0; i < m; i++) {
        cin >> t;
        auto it = s.lower_bound(t);
        if (it != s.end()) {
            cout << *it << endl;
            s.erase(it);
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}