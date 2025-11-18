#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> a(n); vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	vector<string> ops;

	int switch_cnt = 0;
	do {
		int temp_op_cnt = 0;
		for (int i = 0; i < n-1; i++) {
			if (a[i] > a[i+1]) {
				int t = a[i+1];
				a[i+1] = a[i];
				a[i] = t;
				temp_op_cnt++;
				ops.push_back("1 " + to_string(i+1) + "\n");
			}
		}	
		switch_cnt = temp_op_cnt;
	} while (switch_cnt > 0);


	do {
		int temp_op_cnt = 0;
		for (int i = 0; i < n-1; i++) {
			if (b[i] > b[i+1]) {
				int t = b[i+1];
				b[i+1] = b[i];
				b[i] = t;
				temp_op_cnt++;
				ops.push_back("2 " + to_string(i+1) + "\n");
			}
		}
		switch_cnt = temp_op_cnt;
	} while (switch_cnt > 0);

	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			int t = b[i];
			b[i] = a[i];
			a[i] = t;
			ops.push_back("3 " + to_string(i+1) + "\n");
		}
	}

	cout << ops.size() << endl;
	for (string op : ops) cout << op; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while (t--) solve();

	return 0;
}
