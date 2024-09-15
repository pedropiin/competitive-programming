#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll n;
    cin >> n;
 
    if (n > 3 || n == 1) {
        for (ll i = 2; i <= n; i += 2) {
            cout << i << ' ';
        }
        for (ll i = 1; i <= n; i += 2) {
            cout << i << ' ';
        }
        cout << endl;
    } else {
        cout << "NO SOLUTION" << endl;
    }
 
    return 0;
}

