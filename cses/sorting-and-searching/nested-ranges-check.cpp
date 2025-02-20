#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct compare_second {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        return a.second < b.second;
    }
};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i] = {i, {a, b}};
    }

    sort(v.begin(), v.end(),
        [](const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) -> bool {
            if (a.second.first != b.second.first) {
                return a.second.first < b.second.first;
            } else {
                return a.second.second > b.second.second;
            }
        }
    );

    set<pair<int, int>, compare_second> contains;
    contains.insert(v[n - 1].second);

    vector<int> ans_contains;
    ans_contains.push_back(0);
    set<pair<int, int>>::iterator it;
    for (int i = (n - 2); i >= 0; i--) {
        it = contains.upper_bound(v[i].second);

        if (it == contains.begin()) {
            ans_contains.push_back(0);
        } else {
            ans_contains.push_back(1);
        }
        contains.insert(it, v[i].second);
    }

    reverse(ans_contains.begin(), ans_contains.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[v[i].first] = ans_contains[i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    set<pair<int, int>, compare_second> in;
    in.insert(v[0].second);

    vector<int> ans_in;
    ans_in.push_back(0);
    for (int i = 1; i < n; i++) {
        it = in.lower_bound(v[i].second);

        if (it == in.end()) {
            ans_in.push_back(0);
        } else {
            ans_in.push_back(1);
        }
        in.insert(it, v[i].second);
    }
    
    for (int i = 0; i < n; i++) {
        ans[v[i].first] = ans_in[i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

