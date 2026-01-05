#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int ok = 1;
	unordered_map<int, int> mp;
	vector<vector<int>> apps(26, vector<int>());
	int num_cnt = 0;
	int first = v[0]; mp[first] = 0; num_cnt++; apps[0].push_back(0);

	for (int i = 1; i < n; i++) {
		if (num_cnt > 26) {
			ok = 0; break;
		}
		
		if (mp[v[i]] == 0 && v[i] != first) {
			if (num_cnt == 26) {
				ok = 0; break;
			}
			mp[v[i]] = num_cnt++; 
			apps[mp[v[i]]].push_back(i);
		} else if (mp[v[i]] != 0 || v[i] == first) {
			apps[mp[v[i]]].push_back(i);
		}
	}
	if (num_cnt > 26) ok = 0;

	int m; cin >> m;
	while (m--) {
		string s; cin >> s;
		int len = s.length();
		if (len != n || !ok) {
			cout << "NO" << endl;
			continue;
		}

		unordered_map<char, int> mp_str;
		vector<vector<int>> apps_str(26, vector<int>());
		int char_cnt = 0; mp_str[s[0]] = char_cnt++; apps_str[0].push_back(0);
		for (int i = 1; i < len; i++) {
			if (mp_str[s[i]] == 0 && s[i] != s[0]) {
				mp_str[s[i]] = char_cnt++;
			}

			apps_str[mp_str[s[i]]].push_back(i);
		}

		int ok = 1;
		for (int i = 0; i < 26; i++) {
			if (apps[i].size() != apps_str[i].size()) {
				ok = 0; break;
			}
			for (int j = 0; j < apps[i].size(); j++) {
				if (apps[i][j] != apps_str[i][j]) {
					ok = 0; break;
				}
			}
			
			if (!ok) break;
		}
		if (!ok) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
