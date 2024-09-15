#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        ll sum = a + b + c;
        int rounds = sum / 9;
        int rem = sum % 9;
        if (a < rounds || b < rounds || c < rounds) {
            cout << "NO\n";
        } else if (rem != 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}