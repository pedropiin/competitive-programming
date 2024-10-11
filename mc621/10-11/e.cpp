#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p;
	cin >> p;
	
	switch (p) {
		case 0:
		case 1:
		case 2:
			cout << 0 << endl;
			break;
		default:
			cout << (p - 2) << endl;
			break;
	}

	return 0;
}
