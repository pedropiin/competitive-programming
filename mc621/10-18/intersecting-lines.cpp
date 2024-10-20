#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double cross_product(pair<double, double> &p1, pair<double, double> &p2, pair<double, double> &p3) {
	double xtmp1 = (p3.first - p1.first);
	double ytmp1 = (p3.second - p1.second);
	double xtmp2 = (p3.first - p2.first);
	double ytmp2 = (p3.second - p2.second);

	return (xtmp1 * ytmp2) - (xtmp2 * ytmp1);
}

// 0 if p1 is smaller and 1 if p2 is smaller
int compare_points(pair<double, double> &p1, pair<double, double> &p2) {
	if (p1.first == p2.first) {
		return p2.second > p1.second;
	} else {
		return p2.first > p1.first;
	}
}

int is_between(pair<double, double> &p1, pair<double, double> &p2, pair<double, double> &p3) {
	int comp1_3 = compare_points(p1, p3);
	int comp2_3 = compare_points(p2, p3);
	
	if (comp1_3 != comp2_3) {
		return 1;
	}
	return 0;
}

int get_sign(ll n) {
	return (n > 0) - (n < 0);
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

    cout << setprecision(2) << fixed;
    cout << "INTERSECTING LINES OUTPUT" << endl;
	while (t--) {
		pair<double, double> p1, p2, p3, p4;
		cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;

		double cross1 = cross_product(p1, p2, p3);
		double cross2 = cross_product(p1, p2, p4);
		double cross3 = cross_product(p3, p4, p1);
		double cross4 = cross_product(p3, p4, p2);

        // checking if lines overlap
        if (cross1 == 0 || cross2 == 0 || cross3 == 0 || cross4 == 0) {
            cout << "LINE" << endl;
            continue;
        }

		// checking if lines intersect
		if (get_sign(cross1) != get_sign(cross2) && get_sign(cross3) != get_sign(cross4)) {
            double xintersect, yintersect;

            // vertical line
            if (p1.first == p2.first) {
                double m2 = (p4.second - p3.second) / (p4.first - p3.first);
                xintersect = p1.first;
                yintersect = m2 * (xintersect - p3.first) + p3.second;
            } else if (p3.first == p4.first) {
                double m1 = (p2.second - p1.second) / (p2.first - p1.first);
                xintersect = p3.first;
                yintersect = m1 * (xintersect - p1.first) + p1.second;
            } else {
                double m1 = (p2.second - p1.second) / (p2.first - p1.first);
                double m2 = (p4.second - p3.second) / (p4.first - p3.first);

                double c1 = p1.second - m1 * p1.first;
                double c2 = p3.second - m2 * p3.first;

                xintersect = (c2 - c1) / (m1 - m2);
                yintersect = m1 * xintersect + c1;
            }

			cout << "POINT " << xintersect << " " << yintersect << endl;
			continue;
		}

		cout << "NONE" << endl;
	}
    cout << "END OF OUTPUT" << endl;

	return 0;
}
