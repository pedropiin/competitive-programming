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


int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	// sorting points
	sort(v.begin(), v.end(), [](const pair<int, int> &left, const pair<int, int> &right){
		if (left.first == right.first) {
			return left.second < right.second;
		}
		return left.first < right.first;
	});

	vector<pair<int, int>> hull;
	vector<pair<int, int>>::iterator it;
	hull.push_back(v[0]);
	hull.push_back(v[1]);

	// building upper hull
	int last = 1; // points to the last element of the hull
	for (int i = 2; i < n; i++) {
		while (last >= 1 && cross_product(hull[last - 1], hull[last], v[i]) > 0) {
			hull.pop_back();
			last--;
		}
		hull.push_back(v[i]);
		last++;
	}
	int t = hull.size();
	for (int i = (n - 2); i >= 0; i--) {
		while (last >= t && cross_product(hull[last - 1], hull[last], v[i]) > 0) {
			hull.pop_back();
			last--;
		}
		hull.push_back(v[i]);
		last++;
	}
	
	hull.pop_back();
	last--;

	cout << last + 1 << endl;
	for (int i = 0; i <= last; i++) {
		cout << hull[i].first << " " << hull[i].second << endl;
	}

	return 0;
}
