#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll num, divisor = 5;
    cin >> num;
    int x = 0;
 
    while (divisor <= num || divisor == num) {
        x += num / divisor;
        divisor *= 5;
    }
 
    cout << x << endl;
 
    return 0;
}

