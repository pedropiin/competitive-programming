#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    ll a, b;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a == 0 ^ b == 0) {
            cout << "NO" << endl;
        } else {
            if (a < (b / 2)) {
                cout << "NO" << endl;
            } else if (b < (a / 2)) {
                cout << "NO" << endl;
            } else {
                if ((a + b) % 3 == 0) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        }
    }
 
    return 0;
}

