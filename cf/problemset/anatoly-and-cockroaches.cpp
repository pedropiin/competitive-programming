#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int r = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'r') r++;
		else b++;
	}
	
	vector<int> wrong_r, wrong_b;
	int ans_r, ans_b;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0 && s[i] == 'b') wrong_b.push_back(i);
		else if (i % 2 == 1 && s[i] == 'r') wrong_r.push_back(i);
	}
	int mn = min(wrong_b.size(), wrong_r.size());
	ans_r = mn + (wrong_b.size()-mn) + (wrong_r.size() -mn);

	wrong_r.clear();
	wrong_b.clear();
	for (int i = 0; i < n; i++) {
		if (i%2 == 0 && s[i] == 'r') wrong_r.push_back(i);
		else if (i%2 == 1 && s[i] == 'b') wrong_b.push_back(i);
	}
	mn = min(wrong_b.size(), wrong_r.size());
	ans_b = mn + (wrong_b.size()-mn) + (wrong_r.size()-mn);

	cout << min(ans_r, ans_b) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

