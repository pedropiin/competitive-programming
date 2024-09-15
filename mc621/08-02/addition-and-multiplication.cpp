// Problem F

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int x = 1;
    for (int i = 0; i < n; i++) {
        if (x < k) {
            x *= 2;
        } else {
            x += k;
        }
    }
    cout << x << endl;

    return 0;
}