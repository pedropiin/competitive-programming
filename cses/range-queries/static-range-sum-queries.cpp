#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<ll> sum(n + 1);

    sum[0] = 0;
    cin >> arr[0];
    sum[1] = arr[0];
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        sum[i + 1] = sum[i] + arr[i];
    }

    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << endl;
    }

    return 0;
}