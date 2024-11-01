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

    int n;
    cin >> n;
    while (n != 0) {
        vector<pair<int, int>> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }
        ll last = 0, curr = 0;
        int convex = 0;
        for (int i = 0; i < n; i++) {
            curr = cross_product(points[i], points[(i + 1) % n], points[(i + 2) % n]);
            if (last * curr < 0) {
                // convex
                convex = 1;
                break;
            } else {
                last = curr;
            }
        }

        if (convex) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        cin >> n;
    }
    return 0;
}