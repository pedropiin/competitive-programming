#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, x; cin >> n >> x;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	unordered_map<int, vector<pair<int, int>>> freq;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			freq[v[i] + v[j]].push_back({i, j});
		}
	}

	for (auto left : freq) {
		auto it = freq.find(x - left.first);
		if (it != freq.end()) {
			for (pair<int, int> pairl : left.second) {
				for (pair<int, int> pairr : it->second) {
					if (pairl.first != pairr.first && pairl.first != pairr.second && pairl.second != pairr.first && pairl.second != pairr.second) {
						cout << pairl.first+1 << " " << pairl.second+1 << " " << pairr.first+1 << " " << pairr.second+1 << endl;
						return;
					}
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}

