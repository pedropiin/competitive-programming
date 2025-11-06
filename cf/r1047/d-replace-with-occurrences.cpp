#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	unordered_map<int, int> freq;
	unordered_set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		freq[v[i]]++;	
		s.insert(v[i]);
	}
	unordered_map<int, int>::iterator it;
	for (it = freq.begin(); it != freq.end(); it++) {
		if (it->second % it->first != 0) {
			cout << -1 << endl;
			return;
		}
	}
	
	unordered_map<int, pair<vector<int>,int>> m;
	unordered_set<int>::iterator it_set;
	for (it_set = s.begin(); it_set != s.end(); it_set++) {
		m[*it_set] = make_pair(vector<int>(), -1);
	}

	int global_counter = 1;
	for (it_set = s.begin(); it_set != s.end(); it_set++) {
		int amount = freq[*it_set] / *it_set;
		for (int i = 0; i < amount; i++) {
			m[*it_set].first.push_back(global_counter);
			global_counter++;
		}
		m[*it_set].second = 0;
	}

	vector<int> ans;
	unordered_map<int, pair<vector<int>, int>>::iterator it_m;

	for (int og_freq : v) {
		ans.push_back(m[og_freq].first[m[og_freq].second]);
		freq[og_freq]--;
		if (freq[og_freq] % og_freq == 0) m[og_freq].second++;
	}

	for (auto val : ans) cout << val << " ";
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
