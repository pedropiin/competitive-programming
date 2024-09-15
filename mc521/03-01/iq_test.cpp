#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, num;
    vector <int> v;
    cin >> n;
    int t0, t1, t2;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    
    t0 = v[0] % 2;
    t1 = v[1] % 2;
    t2 = v[2] % 2;
    int soma = t0 + t1 + t2;
    if (soma == 0 || soma == 1) {
        for (int i = 0; i < n; i++) {
            if ((v[i] % 2) != 0) {
                cout << i + 1 << endl;
                break;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if ((v[i] % 2) == 0) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    
    return 0;
}