#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q, a, b, juncao[n];
    char op;
    cin >> n >> q;
    map<int, set<int>> m;

    for (int i = 0; i < n; i++) {
        set<int> new_set;
        new_set.insert(i);
        m.insert({i, new_set});
    }

    for (int i = 0; i < q; i++) {
        cin >> op >> a >> b;
        if (op == '?') {
            if (m[a].count(b) != 0) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        } else if (op == '=') {
            if (m[a].size() >= m[b].size()) {
                for (set<int>::iterator it = m[b].begin(); it != m[b].end(); it++) {
                    m[a].insert(*it);
                }
                m[b] = m[a];
            } else {
                for (set<int>::iterator it = m[a].begin(); it != m[a].end(); it++) {
                    m[b].insert(*it);
                }
                m[a] = m[b];
            }
        }
        for (set<int>::iterator it = m[1].begin(); it != m[1].end(); it++) {
            cout << ' ' << *it;
        }
        for (set<int>::iterator it = m[8].begin(); it != m[8].end(); it++) {
            cout << ' ' << *it;
        }
        cout << '\n';
    }

    return 0;
}