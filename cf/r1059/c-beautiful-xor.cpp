#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve() {
	int a, b;
	cin >> a >> b;
 
	bitset<32> bit_a(a);
	bitset<32> bit_b(b);
 
	int msb_a, msb_b;
	for (int i = 31; i >= 0; i--) {
		if (bit_a[i] == 1) {
			msb_a = i;
			break;
		}
	}
	for (int i = 31; i >= 0; i--) {
		if (bit_b[i] == 1) {
			msb_b = i;
			break;
		}
	}
	if (msb_b > msb_a) {
		cout << -1 << endl;
		return;
	}
 
	vector<int> vals;
	int temp = 1;
	for (int i = 0; i <= msb_a; i++) {
		if (bit_a[i] == 0) {
			bit_a[i] = 1;
			vals.push_back(temp);
		}
		temp = temp << 1;
	}
	temp = 1;
	for (int i = 0; i <= msb_a; i++) {
		if (bit_b[i] == 0) {
			vals.push_back(temp);
		}
		temp = temp << 1;
	}
 
	cout << vals.size() << endl;
	for (auto v : vals) cout << v << " ";
	cout << endl;
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
