#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<int, int>> cops;
vector<pair<int, int>> robbers;
vector<pair<int, int>> oss;
vector<int> with_cops;
vector<int> with_robbers;
vector<pair<int, int>> triangle;


ll cross_product(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &p3) {
	ll xtmp1 = (p3.first - p1.first);
	ll ytmp1 = (p3.second - p1.second);
	ll xtmp2 = (p3.first - p2.first);
	ll ytmp2 = (p3.second - p2.second);

	ll cross = (xtmp1 * ytmp2) - (xtmp2 * ytmp1);
	return cross;
}

int area_triangle() {
    ll t1 = triangle[0].first * (triangle[1].second - triangle[2].second);
    ll t2 = triangle[1].first * (triangle[2].second - triangle[0].second);
    ll t3 = triangle[2].first * (triangle[0].second - triangle[1].second);
    ll area = t1 + t2 + t3;

    if (area > 0) {
        return 1;
    } else {
        return 0;
    }
}

int inside_triangle(pair<int, int> &point) {
    int inside = 1;
    int orientation = area_triangle();
    for (int i = 0; i < 3; i++) {
        if (orientation == 0) {
            // negative area triangle
            if (cross_product(triangle[i], triangle[(i + 1) % 3], point) > 0) {
                inside = 0;
                break;
            }
        } else {
            // posiive area triangle
            if (cross_product(triangle[i], triangle[(i + 1) % 3], point) < 0) {
                inside = 0;
                break;
            }
        }
    }
    return inside;
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c, r, o;
    cin >> c >> r >> o;
    int test_num = 1;
    int xtemp, ytemp;
    while (c != 0 || r != 0 || o != 0) {
        for (int i = 0; i < c; i++) {
            cin >> xtemp >> ytemp;
            cops.push_back(make_pair(xtemp, ytemp));
        }

        for (int i = 0; i < r; i++) {
            cin >> xtemp >> ytemp;
            robbers.push_back(make_pair(xtemp, ytemp));
        }

        for (int i = 0; i < o; i++) {
            cin >> xtemp >> ytemp;
            oss.push_back(make_pair(xtemp, ytemp));
        }

        with_cops.assign(o, 0);
        with_robbers.assign(o, 0);

        // TODO: deal with case in which there are less than 3 robbers and case with less than 3 cops

        // checking if are safe
        for (int i = 0; i < (c - 2); i++) {
            for (int j = (i + 1); j < (c - 1); j++) {
                for (int k = (j + 1); k < c; k++) {
                    // all possible triangles of cops
                    triangle.push_back(cops[i]); triangle.push_back(robbers[i]); triangle.push_back(oss[i]);
                    sort(triangle.begin(), triangle.end());
                    for (int t = 0; t < o; t++) {
                        // all citizens
                        with_cops[t] = inside_triangle(oss[t]);
                    }
                    triangle.clear();
                }
            }
        }

        for (int i = 0; i < (r - 2); i++) {
            for (int j = (i + 1); j < (r - 1); j++) {
                for (int k = (j + 1); k < r; k++) {
                    // all possible triangles of robbers
                    triangle.push_back(robbers[i]); triangle.push_back(robbers[j]); triangle.push_back(robbers[k]);
                    sort(triangle.begin(), triangle.end());
                    for (int t = 0; t < o; t++) {
                        // all citizens
                        with_robbers[t] = inside_triangle(oss[t]);
                    }
                    triangle.clear();
                }
            }
        }

        cout << "Data set " << test_num++ << ":" << endl;
        for (int i = 0; i < o; i++) {
            if (with_cops[i]) {
                cout << "\t Citizen at (" << oss[i].first << "," << oss[i].second << ") is safe." << endl;
            } else if (!with_cops[i] && with_robbers[i]) {
                cout << "\t Citizen at (" << oss[i].first << "," << oss[i].second << ") is robbed." << endl;
            } else {
                cout << "\t Citizen at (" << oss[i].first << "," << oss[i].second << ") is neither." << endl;
            }
        }

        cops.clear();
        robbers.clear();
        oss.clear();
        with_cops.clear();
        with_robbers.clear();

        cin.ignore();
        cin >> c >> r >> o;
    }

    return 0;
}