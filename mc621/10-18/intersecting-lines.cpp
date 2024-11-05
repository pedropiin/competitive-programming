#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	cout << "INTERSECTING LINES OUTPUT" << endl;
	cout << fixed;
	cout << setprecision(2);
	while (t--) {
		pair<int, int> p1, p2, p3, p4;
		cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;

		if (p1.first == p2.first) {
			// vertical line or just a point
			if (p3.first == p4.first) {
				// also a vertical line or just a point
				if (p1.first == p3.first) {
					// all are in the same vertical line
					cout << "LINE" << endl;
				} else {
					// parallel vertical lines
					cout << "NONE" << endl;
				}
			} else {
				// definitely intersect, as one of them is vertical and the other isn't
				float a_temp = (float)(p4.second - p3.second) / (p4.first - p3.first);
				float b_temp = p4.second - a_temp * p4.first;

				cout << "POINT " << (float)p1.first << " " << (a_temp * p1.first + b_temp) << endl;
			}
		} else {
			// first line is a "normal" lines
			float a1 = (float)(p2.second - p1.second) / (p2.first - p1.first);
			float b1 = p1.second - a1 * p1.first;

			if (p3.first == p4.first) {
				// second line is vertical and the first isn't, so there is intersection
				cout << "POINT " << (float)p3.first << " " << (a1 * p3.first + b1) << endl;
			} else {
				// both are "normal" lines
				float a2 = (float)(p4.second - p3.second) / (p4.first - p3.first);
				float b2 = p3.second - a2 * p3.first;

				if (a1 == a2) {
					// parallel
					if (b1 == b2) {
						// same line
						cout << "LINE" << endl;
					} else {
						// parallel and not concurrent
						cout << "NONE" << endl;
					}
				} else {
					float x_intersect = (b2 - b1) / (a1 - a2);
					cout << "POINT " << x_intersect << " " << a1 * x_intersect + b1 << endl;
				}
			}
		}
	}
	cout << "END OF OUTPUT" << endl;

	return 0;
}