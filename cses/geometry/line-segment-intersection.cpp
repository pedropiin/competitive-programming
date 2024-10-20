#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cross_product(pair<ll, ll> &p1, pair<ll, ll> &p2, pair<ll, ll> &p3) {
	ll xtmp1 = (p3.first - p1.first);
	ll ytmp1 = (p3.second - p1.second);
	ll xtmp2 = (p3.first - p2.first);
	ll ytmp2 = (p3.second - p2.second);

	return (xtmp1 * ytmp2) - (xtmp2 * ytmp1);
}

// 0 if p1 is smaller and 1 if p2 is smaller
int compare_points(pair<ll, ll> &p1, pair<ll, ll> &p2) {
	if (p1.first == p2.first) {
		return p2.second > p1.second;
	} else {
		return p2.first > p1.first;
	}
}

int is_between(pair<ll, ll> &p1, pair<ll, ll> &p2, pair<ll, ll> &p3) {
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
	while (t--) {
		pair<ll, ll> p1, p2, p3, p4;
		cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;

		ll cross1 = cross_product(p1, p2, p3);
		ll cross2 = cross_product(p1, p2, p4);
		ll cross3 = cross_product(p3, p4, p1);
		ll cross4 = cross_product(p3, p4, p2);

		// checking if lines overlap
		if (cross1 == 0 && is_between(p1, p2, p3)) {
			cout << "YES" << endl;
			continue;
		}
		if (cross2 == 0 && is_between(p1, p2, p4)) {
			cout << "YES" << endl;
			continue;
		} 
		if (cross3 == 0 && is_between(p3, p4, p1)) {
			cout << "YES" << endl;
			continue;
		} 
		if (cross4 == 0 && is_between(p3, p4, p2)) {
			cout << "YES" << endl;
			continue;
		} 

		// checking if lines intersect
		if (get_sign(cross1) != get_sign(cross2) && get_sign(cross3) != get_sign(cross4)) {
			cout << "YES" << endl;
			continue;
		}

		cout << "NO" << endl;
	}

	return 0;
}
