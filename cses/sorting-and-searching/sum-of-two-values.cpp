#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    ll x;
    cin >> n >> x;
 
    map <ll, ll> umap;
 
    int achou = 0;
    ll num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (umap.find(x - num) == umap.end()) {
            umap[num] = i;
        } else {
            cout << umap[x - num] + 1 << ' ' << i + 1 << endl;
            achou = 1;
            break;
        }
    }
    
    if (!achou) {
        cout << "IMPOSSIBLE" << endl;
    }
 
    return 0;
}

