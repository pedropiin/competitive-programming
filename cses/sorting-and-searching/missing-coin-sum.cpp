#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    ll s = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > s + 1) {
            cout << s + 1 << endl;
            ans = 1;
            break;
        }
        s += v[i];
    }

    if (!ans) {
        cout << s + 1 << endl;
    }

    return 0;
}
