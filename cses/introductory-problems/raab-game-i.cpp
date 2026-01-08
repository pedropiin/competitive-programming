#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, a, b; cin >> n >> a >> b;

    if ((a + b) == 0 || (a > 0 && b > 0 && a+b <= n)) {
       int t = n-a-b;
       vector<int> aret, bret;
       for (int i = 1; i <= n; i++) aret.push_back(i);

       for (int i = 1; i <= n; i++) {
           if (i <= b) bret.push_back(i+a);
           else if (i <= a+b) bret.push_back(i-b);
           else bret.push_back(i);
       }

       cout << "YES" << endl;
       for (int elem : aret) cout << elem << " ";
       cout << endl;
       for (int elem : bret) cout << elem << " ";
       cout << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
