#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    ll v[n];
    ll moves = 0;
 
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i >= 1) {
            if (v[i] < v[i-1]) {
                moves += v[i - 1] - v[i];
                v[i] = v[i - 1];
            }
        }
    }
 
    cout << moves << endl;
 
    return 0;
}

