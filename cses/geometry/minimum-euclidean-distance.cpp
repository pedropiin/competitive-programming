#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll euclidean_distance(pair<int, int> &p1, pair<int, int> &p2) {
    return (ll)(p1.first - p2.first) * (ll)(p1.first - p2.first) + (ll)(p1.second - p2.second) * (ll)(p1.second - p2.second);
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> points;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        points.push_back(make_pair(a, b));
    }

    sort(points.begin(), points.end());

    ll min_dist = LLONG_MAX;
    set<pair<int, int>> valid;
    valid.insert({points[0].second, points[0].first});
    int j = 0;
    for (int i = 1; i < n; i++) {
        ll dist_root = ceil(sqrt(min_dist));
        cout << "when i started with value " << i << " mind_dist = " << min_dist << " and d_root = " << dist_root << endl;
        while (j < i && points[j].first < points[i].first - dist_root) {
            valid.erase({points[j].second, points[j].first});
            j++;
        }

        for (auto p : valid) {
            cout << "------- " << p.first << " " << p.second << endl;
        }

        set<pair<int, int>>::iterator low = valid.lower_bound({points[i].second - dist_root, 0});
        set<pair<int, int>>::iterator up = valid.upper_bound({points[i].second + dist_root, 0});
        set<pair<int, int>>::iterator it;
        ll temp_dist;
        cout << "low points to " << low->second << " " << low->first << " and up points to " << up->second << " " << up->first << endl;
        for (it = low; it != up; it++) {
            pair<int, int> elem = make_pair(it->second, it->first);
            temp_dist = euclidean_distance(points[i], elem);
            cout << "comparing point i = " << points[i].first << " " << points[i].second << " and elem = " << elem.first << " " << elem.second << endl;
            cout << "temp dist = " << temp_dist << endl;
            min_dist = min(min_dist, temp_dist);
            cout << "now min_dist = " << min_dist << endl;
        }
        valid.insert({points[i].second, points[i].first});
    }

    cout << min_dist << endl;

    return 0;
}
