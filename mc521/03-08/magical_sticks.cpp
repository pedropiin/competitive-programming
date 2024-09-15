#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, count;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        count = n / 2;
        if (n % 2 == 1) {
            count++;
        }
        cout << count << endl;
    }

    return 0;
}