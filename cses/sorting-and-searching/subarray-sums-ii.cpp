#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;
	vector<ll> ps = {0};
	map<ll, int> m;
	m[0] = 1;
	ll count = 0;
	int t, temp;
	for (int i = 0; i < n; i++) {
		cin >> t;
		ps.push_back(t + ps[i]);
		count += m[ps[i + 1] - x];
		m[ps[i + 1]]++;
	}

	cout << count << endl;

	return 0;

}
