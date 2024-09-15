#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, x;
    cin >> n >> x;
    int v[n];
    bool tem_gondola[n] = {false};
 
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v, v + n);
 
    int i = 0, j = n - 1, contador = 0;
    while (i < j) {
        if (v[i] + v[j] <= x) {
            contador += 1;
            tem_gondola[i] = true;
            tem_gondola[j] = true;
            i++;
            j--;
        } else {
            j--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (tem_gondola[i] == false) {
            contador++;
        }
    }
 
    cout << contador << endl;
    return 0;
}

