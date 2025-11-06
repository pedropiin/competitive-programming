#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve() {
    int n;
    cin >> n;
    string s; 
    cin >> s;

    int one_cnt = 0;
    for (int i = 0; i < n; i++) one_cnt += s[i] - '0';

    if (one_cnt > 0) {
        cout << one_cnt << endl;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cout << i + 1 << " ";
        }
        cout << endl;
    } else {
        cout << 0 << endl;
    }
}


int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}