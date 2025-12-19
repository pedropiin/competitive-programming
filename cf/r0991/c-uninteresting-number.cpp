#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string s; cin >> s;
	int summ = 0;
	vector<int> freq(10, 0);
	for (char c : s) {
		summ += c -'0';
		freq[c-'0']++;
	}

	int mod = summ % 9;
	int ans = 0;
	switch (mod) {
		case 0:
			ans = 1;	
			break;
		case 8: 
			if ((freq[2] >= 5) || (freq[2] >= 2 && freq[3] >= 1)) 
				ans = 1;	
			break;
		case 7:
			if (freq[2] >= 1)
				ans = 1;
			break;
		case 6:
			if ((freq[3] >= 2) || (freq[2] >= 6) || (freq[3] >= 1 && freq[2] >= 3)) 
				ans = 1;
			break;
		case 5:
			if (freq[2] >= 2) 
				ans = 1;
			break;
		case 4:
			if ((freq[3] >= 2 && freq[2] >= 1) || (freq[2] >= 7) || (freq[3] >= 1 && freq[2] >= 4)) 
				ans = 1;
			break;
		case 3:
			if (freq[3] >= 1 || freq[2] >= 3)
				ans = 1;
			break;
		case 2:
			if ((freq[3] >= 2 && freq[2] >= 2) || (freq[2] >= 8) || (freq[3] >= 1 && freq[2] >= 5)) 
				ans = 1;
			break;
		case 1: 
			if (freq[2] >= 4 || (freq[3] >= 1 && freq[2] >= 1)) 
				ans = 1;
			break;
	}
	
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
