#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll n, num;
    cin >> n;
 
    cout << 0 << endl;
    for (ll i = 2; i <= n; i++) {
        num = (((i * i) * ((i * i) - 1)) / 2) - (4 * (i - 1) * (i -2 ));
        cout << num << endl;
    }
    
 
    return 0;
}

