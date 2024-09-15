#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, num;
    cin >> n;
    vector<int> v(n);
 
    for (int i = 0; i < n - 1; i++) {
        cin >> num;
        v[num - 1] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            cout << i + 1 << endl;
            break;
        }
    }
    
    return 0;
}

