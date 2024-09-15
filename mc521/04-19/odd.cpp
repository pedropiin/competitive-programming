#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;
    for (int a = 0; a < t; a++) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int possible = 0, count = 0;
        for (int i = 0; i < (n - 1); i++) {
            if (v[i] > v[i + 1] && possible == 0) {
                count++;
                possible = 1;
            } else {
                possible = 0;
            }
        }
        cout << count << endl;
    }

    return 0;
}