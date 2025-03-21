#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> idx(n + 1);
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		idx[t] = i;
	}

	int count = 1;
	for (int i = 1; i < n; i++) {
		if (idx[i + 1] < idx[i]) {
			count++;
		}
	}

	cout << count << endl;
	
	return 0;
}
