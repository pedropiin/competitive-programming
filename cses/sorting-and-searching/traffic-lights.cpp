#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return (a.second - a.first) < (b.second - b.first);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, n; cin >> x >> n;

    set<int> lights; lights.insert(0); lights.insert(x);
    multiset<int> gaps; gaps.insert(x);
    set<int>::iterator previous, next;
    int curr;
    for (int i = 0; i < n; i++) {
        cin >> curr;
        next = lights.upper_bound(curr);
        previous = next; previous--;

        gaps.erase(gaps.find(*next - *previous));
        gaps.insert(curr - *previous);
        gaps.insert(*next - curr);
        cout << *(gaps.rbegin()) << " ";
        lights.insert(curr);
    }
    cout << endl;

    return 0;
}
