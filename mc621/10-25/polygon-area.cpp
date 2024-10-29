#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> points(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}

	// using shoelace formula
	ll area = 0;
	for (int i = 0; i < (n - 1); i++) {
		area += ((ll)points[i].first * (ll)points[i + 1].second) - ((ll)points[i + 1].first * (ll)points[i].second);
	}
	area += (ll)((ll)points[n - 1].first * (ll)points[0].second) - (ll)((ll)points[0].first * (ll)points[n - 1].second);

	cout << abs(area) << endl;

	return 0;
}
