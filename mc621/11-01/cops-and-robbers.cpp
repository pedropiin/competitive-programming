#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cross_product(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &p3) {
    if (p1.first == p2.first && p1.second == p2.second) {
        if (p1.first != p3.first || p1.second != p3.second) {
            return 1;
        }
        return -1;
    }

	ll xtmp1 = (p3.first - p1.first);
	ll ytmp1 = (p3.second - p1.second); 
	ll xtmp2 = (p3.first - p2.first);
	ll ytmp2 = (p3.second - p2.second);

	ll cross = (xtmp1 * ytmp2) - (xtmp2 * ytmp1);
	return cross;
}

vector<pair<int, int>> convex_hull(vector<pair<int, int>> &points) {
    int n = points.size();

	vector<pair<int, int>> hull;
	vector<pair<int, int>>::iterator it;
	hull.push_back(points[0]);
	hull.push_back(points[1]);

	// building upper hull
	int last = 1; // points to the last element of the hull
	for (int i = 2; i < n; i++) {
		while (last >= 1 && cross_product(hull[last - 1], hull[last], points[i]) > 0) {
			hull.pop_back();
			last--;
		}
		hull.push_back(points[i]);
		last++;
	}
	int t = hull.size();
	for (int i = (n - 2); i >= 0; i--) {
		while (last >= t && cross_product(hull[last - 1], hull[last], points[i]) > 0) {
			hull.pop_back();
			last--;
		}
		hull.push_back(points[i]);
		last++;
	}
	
	hull.pop_back();
	last--;
    
    return hull;
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c, r, o;
    cin >> c >> r >> o;
    int test_num = 1;
    int xtemp, ytemp;
    while (c != 0 || r != 0 || o != 0) {
        vector<pair<int, int>> cops(c);
        for (int i = 0; i < c; i++) {
            cin >> cops[i].first >> cops[i].second;
        }

        vector<pair<int, int>> robbers(r);
        for (int i = 0; i < r; i++) {
            cin >> robbers[i].first >> robbers[i].second;
        }

        vector<pair<int, int>> oss(o);
        for (int i = 0; i < o; i++) {
            cin >> oss[i].first >> oss[i].second;
        }

        // sorting points
        sort(cops.begin(), cops.end(), [](const pair<int, int> &left, const pair<int, int> &right){
            if (left.first == right.first) {
                return left.second < right.second;
            }
            return left.first < right.first;
        });
        sort(robbers.begin(), robbers.end(), [](const pair<int, int> &left, const pair<int, int> &right){
            if (left.first == right.first) {
                return left.second < right.second;
            }
            return left.first < right.first;
        });

        vector<int> with_cops(o, 0);
        vector<int> with_robbers(o, 0);

        if (c >= 3) {
            vector<pair<int, int>> hull_cops = convex_hull(cops);

            int n = hull_cops.size();
            for (int i = 0; i < o; i++) {
                int in = 1;
                for (int j = 0; j < n; j++) {
                    if (cross_product(hull_cops[j], hull_cops[(j + 1) % n], oss[i]) > 0) {
                        // cout << "o ponto " << oss[i].first << " " << oss[i].second << " está fora do hull dos policiais" << endl;
                        in = 0;
                        break;
                    }
                }
                with_cops[i] = in;
            }
        }

        if (r >= 3) {
            vector<pair<int, int>> hull_robbers = convex_hull(robbers);

            int n = hull_robbers.size();
            for (int i = 0; i < o; i++) {
                int in = 1;
                for (int j = 0; j < n; j++) {
                    if (cross_product(hull_robbers[j], hull_robbers[(j + 1) % n], oss[i]) > 0) {
                        // cout << "o ponto " << oss[i].first << " " << oss[i].second << " está fora do hull dos ladrões" << endl;
                        in = 0;
                        break;
                    }
                }
                with_robbers[i] = in;
            }
        }

        cout << "Data set " << test_num++ << ":" << endl;
        for (int i = 0; i < o; i++) {
            if (with_cops[i]) {
                cout << "\t Citizen at (" << oss[i].first << "," << oss[i].second << ") is safe." << endl;
            } else if (with_robbers[i]) {
                cout << "\t Citizen at (" << oss[i].first << "," << oss[i].second << ") is robbed." << endl;
            } else {
                cout << "\t Citizen at (" << oss[i].first << "," << oss[i].second << ") is neither." << endl;
            }
        }

        cin.ignore();
        cin >> c >> r >> o;
    }

    return 0;
}