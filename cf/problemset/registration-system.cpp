#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, int> m;

	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		int f = m[s]++;
		if (f == 0)	cout << "OK" << endl; 
		else cout << s << f << endl;
	}

	return 0;
}
