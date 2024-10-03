#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void tower_of_hanoi(int n, int l, int m, int r) {
	if (n == 1) {
		cout << l << " " << r << endl;
		return;
	}
	tower_of_hanoi((n - 1), l, r, m);
	cout << l << " " << r << endl;
	tower_of_hanoi((n - 1), m, l, r);
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	cout << pow(2, n) - 1 << endl;
	tower_of_hanoi(n, 1, 2, 3);

	return 0;
}
