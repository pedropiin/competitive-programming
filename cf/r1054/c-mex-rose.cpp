#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> freq(k, 0);
	int temp;
	int k_cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp < k) freq[temp]++;
		else if (temp == k) k_cnt++;
	}
	int miss= 0;
	for (int i = 0; i < k; i++) {
		if (freq[i] == 0) miss++;
	}
	cout << max(miss, k_cnt) << endl;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
