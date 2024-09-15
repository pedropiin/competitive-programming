// Problem N && Problem C

#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n), d(n-1);
    cin >> v[0];
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        d[i-1] = v[i] - v[i-1];
    }

    int gcd = d[0];
    for (int i = 1; i < (n-1); i++) {
        gcd = __gcd(gcd, d[i]);
    }

    int sum = 0;
    for (int i = 0; i < (n-1); i++) {
        sum += (d[i] / gcd) - 1;
    }

    cout << sum << endl;
    return 0;
}