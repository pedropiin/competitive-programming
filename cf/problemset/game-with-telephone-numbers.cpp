#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int turns = (n-11)/2;
	
	vector<int> eights; eights.push_back(-1);
	for (int i = 0; i < n; i++) {
		if (s[i] == '8') eights.push_back(i);
	}
	int cnt = eights.size();
	if (cnt-1 <= turns) {
		cout << "NO" << endl; return;
	}

	int spaces = 0;
	for (int i = 1; i <= turns+1; i++) {
		spaces += abs(eights[i] - eights[i-1])-1;
	}	
	if (spaces > turns) cout << "NO" << endl;
	else cout << "YES" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

