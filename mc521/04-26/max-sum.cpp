#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, num;
    cin >> n;
    vector<int> v(n);
    cin >> v[0];
    ll max = v[0], max_it;
    if (v[0] < 0) {
        max_it = 0;
    } else {
        max_it = v[0];
    }
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        max_it += v[i];
        if (max_it > max) {
            max = max_it;
        } 
        if (max_it < 0) {
            max_it = 0;
        }
    }

    cout << max << endl;

    return 0;
}