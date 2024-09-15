#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll l;
    cin >> n >> l;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll dif = 0;
    for (int i = 0; i < n - 1; i++) {
        if ((a[i + 1] - a[i]) > dif) {
            dif = a[i + 1] - a[i];
        }
    }

    double result = dif / (double)2;

    cout.precision(20);
    if (result >= a[0]) {
        if (result >= (l - a[n-1])) {
            cout << fixed << result << endl;
        } else {
            cout << fixed << l - a[n-1] << endl;
        }
    } else {
        if (a[0] >= (l - a[n-1])) {
            cout << fixed << a[0] << endl;
        } else {
            cout << fixed << l - a[n-1] << endl;
        }
    }

    return 0;
}