#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll n;
    cin >> n;
    vector <int> v1, v2;
    vector <ll> vcount(n, 1);
    ll soma = (n * (n + 1)) / 2;
    
    if (soma % 2 == 0) {
        cout << "YES" << endl;
        ll soma1 = 0, soma2 = 0, k = soma / 2;
 
        for (int i = n; i > 0; i--) {
            if ((i + soma1) < k) {
                v1.push_back(i);
                soma1 += i;
                vcount[i - 1] = 0;
                if ((k - soma1) < i) {
                    v1.push_back(k - soma1);
                    vcount[k - soma1 - 1] = 0;
                    break;
                } else {
                    continue;
                }
            }
        }
 
        cout << v1.size() << endl;
        for (int i = 0; i < v1.size(); i++) {
            cout << v1[i] << ' ';
        }
        cout << endl;
        cout << (n - v1.size()) << endl;
        for (int i = 0; i < n; i++) {
            if (vcount[i] == 1) {
                cout << (i + 1) << ' ';
            }
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
 
    return 0;
}

