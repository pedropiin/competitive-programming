#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    ll x, y, resposta;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x >= y) {
            if (x % 2 == 0) {
                resposta = (x * x) - (y - 1);
            } else {
                resposta = ((x - 1) * (x - 1)) + y;
            }
        } else {
            if (y % 2 == 0) {
                resposta = ((y - 1) * (y - 1)) + x;
            } else {
                resposta = (y * y) - (x - 1);
            }
        }
        cout << resposta << endl;
    }
 
    return 0;
}

