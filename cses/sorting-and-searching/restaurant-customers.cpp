#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int max_size = 1e9;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, 0));
		v.push_back(make_pair(b, 1));
	}

	sort(v.begin(), v.end());

	int t = v.size();
	int count = 0, max = 0;
	for (int i = 0; i < t; i++) {
		if (v[i].second == 0) {
			count++;
		} else {
			if (count > max) {
				max = count;
			}
			count--;
		}
	}
	
	cout << max << endl;

}
