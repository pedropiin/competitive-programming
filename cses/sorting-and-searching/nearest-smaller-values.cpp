#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }

    sort(v.begin(), v.end(), [](const pair<int, int> &left, const pair<int, int> &right){
        if (left.first == right.first) {
            return left.second > right.second;
        }
        return left.first < right.first;
    });

    set<int> idcs;
    set<int>::iterator it;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        it = idcs.lower_bound(v[i].second);
        if (it == idcs.begin()) {
            ans[v[i].second - 1] = 0;
        } else {
            --it;
            ans[v[i].second - 1] = *it;
        }
        idcs.insert(v[i].second);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}