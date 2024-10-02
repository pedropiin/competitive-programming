#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<string> v;
	v.push_back("0");
	v.push_back("1");

	for (int i = 1; i < n; i++) {
		int cur_size = v.size();
		int new_size = cur_size * 2;

		for (int j = 0; j < cur_size; j++) {
			v.push_back(v[cur_size - 1 - j]);
		}

		for (int j = 0; j < new_size; j++) {
			if (j < cur_size) {
				v[j].insert(0, "0");
			} else {
				v[j].insert(0, "1");
			}
		}
	}

	int cur_size = v.size();
	for (int i = 0; i < cur_size; i++) {
		cout << v[i] << endl;
	}
		

	return 0;
}
