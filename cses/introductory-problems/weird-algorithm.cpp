#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll num;
    cin >> num;
    cout << num << ' ';
 
    while (num != 1) {
        if (num % 2 != 0) {
            num = (num * 3) + 1;
        } else {
            num /= 2;
        }
        cout << num << ' ';
    }
 
    cout << endl;
 
    return 0;
}

