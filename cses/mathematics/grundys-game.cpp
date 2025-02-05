#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2005;

int mex(vector<int> &v) {
    set<int> s;
    for (int i = 0; i < v.size(); i++) {
        s.insert(v[i]);
    }

    for (int i = 0; i < maxn; i++) {
        if (s.count(i) == 0) {
            return i;
        }
    }
}

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> dp(maxn + 1, 0);
    for (int i = 3; i <= maxn; i++) {
        vector<int> v;
        for (int j = i - 1; j > (i / 2); j--) {
            v.push_back(dp[j] ^ dp[i - j]);
        }
        dp[i] = mex(v);
    }

    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        if (n > maxn || dp[n] != 0) {
            cout << "first" << endl;
        } else {
            cout << "second" << endl;
        }
    }

    return 0;
}
