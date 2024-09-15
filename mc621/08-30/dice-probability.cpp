#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll possible_sums(int sum, int n) {
    ll count = 0;
    if (n == 1) {
        if (sum <= 6) {
            return 1;
        } else {
            return 0;
        }
    }

    int cur = 1;
    while (cur <= 6) {
        count += possible_sums(sum - cur, n - 1);
        cur++;
    }
    return count;
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    
    ll sum = 0;
    for (int i = a; i <= b; i++) {
        sum += possible_sums(i, n);
    }
    float base = (float)1 / (float)pow(6, n); 
    float res = (float)sum * base;
    cout << setprecision(6) << res << endl;

    return 0;
}