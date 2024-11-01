#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cross_product(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &p3) {
	ll xtmp1 = (p3.first - p1.first);
	ll ytmp1 = (p3.second - p1.second);
	ll xtmp2 = (p3.first - p2.first);
	ll ytmp2 = (p3.second - p2.second);

	ll cross = (xtmp1 * ytmp2) - (xtmp2 * ytmp1);
	return cross;
}


int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    pair<int, int> p;
    int in = 1;
    for (int i = 0; i < q; i++) {
        cin >> p.first >> p.second;
        for (int j = 0; j < n; j++) {
            if (cross_product(points[j], points[(j + 1) % n], p) < 0) {
                in = 0;
                break;
            }
        }
        if (in) {
            cout << "D" << endl;
        } else {
            cout << "F" << endl;
        }
        in = 1;
    }

    return 0;
}