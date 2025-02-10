#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;
    vector<int> v;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        v.push_back(t);
    }

    int l = 0, r = 0;
    int count = 0, sum = v[0];
    while (l < n && r < n) {
        if (sum == s) {
            count++;
            r++;
            sum += v[r];
            sum -= v[l];
            l++;
        } else if (sum > s) {
            sum -= v[l];
            l++;
        } else {
            r++;
            sum += v[r];
        }
    }

    cout << count << endl;

    return 0;
}