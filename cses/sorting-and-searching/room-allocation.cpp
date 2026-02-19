#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v(n, {0, 0});
    vector<int> idxs(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        idxs[i] = i; 
    }
    vector<pair<int, int>> sorted_v(v);
    sort(idxs.begin(), idxs.end(), [&](const int &a, const int &b) {
                return v[a] < v[b]; 
            });
    for (int i = 0; i < n; i++) {
        sorted_v[i] = v[idxs[i]];
    } 

    vector<int> room(n, 0);
    int cnt = 1;
    set<pair<int, int>> s;
    s.insert({sorted_v[0].second, cnt});
    room[idxs[0]] = 1;
    set<pair<int, int>>::iterator it;
    for (int i = 1; i < n; i++) {
        it = s.lower_bound({sorted_v[i].first, -1});
        if (it == s.begin()) {
            cnt++;
            room[idxs[i]] = cnt;
            s.insert({sorted_v[i].second, cnt});
        } else {
            it--;
            int d = (*it).second;
            s.erase(it);
            s.insert({sorted_v[i].second, d});
            room[idxs[i]] = d; 
        }
    }

    cout << cnt << endl;
    for (int v : room) cout << v << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--) solve();

    return 0;
}
