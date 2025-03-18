#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    vector<int>::iterator it;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        it = upper_bound(v.begin(), v.end(), t);
        if (it == v.end()) {
            v.push_back(t);
        } else {
            *it = t;
        }
    }

    cout << v.size() << endl;

    return 0;
}