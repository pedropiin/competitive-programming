#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve(int a, int b, int c) {
    for (int x = -100; x <= 100; x++) {
        for (int y = -100; y <= 100; y++) {
            for (int z = -100; z <= 100; z++) {
                if (x != y && y != z && x != z) {
                    if ((x + y + z) == a) {
                        if ((x * y * z) == b) {
                            if (((x * x) + (y * y) + (z * z)) == c) {
                                cout << x << ' ' << y << ' ' << z << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No solution." << endl;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b, c;
    cin >> n;

    int x, y, z, sol;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        sol = solve(a, b, c);
    }
    return 0;
}