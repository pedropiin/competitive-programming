#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int modulo = 1e9 + 7, n, i, resto = 1;
    
    cin >> n;
    for (i = 0; i < n; i++) {
        resto = (resto * 2) % modulo;
 
    }
    cout << resto << '\n';
    return 0;
}

