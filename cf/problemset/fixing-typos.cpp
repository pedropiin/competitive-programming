#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string s; cin >> s;
	vector<int> freq;
	for (int i = 0; i < s.size(); i++) {
		int cnt = 1;
		while (i < s.size()-1 && s[i] == s[i+1]) {
			cnt++;
			i++;
		}
		freq.push_back(cnt);
	}
	vector<int> og_freq(freq);

	int n = freq.size();
	for (int i = 0; i < n; i++) {
		if (freq[i] == 1) continue;
		if (freq[i] == 2) {
			if (i+1 < n && freq[i+1] >= 2) freq[i+1] = 1;
		}
		if (freq[i] >= 3) {
			freq[i] = 2;
			if (i+1 < n && freq[i+1] >= 2) freq[i+1] = 1;
		}
	}

	string ans = ""; 
	int j = 0;
	for (int i = 0; i < n; i++) {
		ans.append(freq[i], s[j]);
		j += og_freq[i];
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}

