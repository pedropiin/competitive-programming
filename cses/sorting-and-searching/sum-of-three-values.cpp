#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, target;
	cin >> n >> target;
	
	map<ll, ll> hmap;
	vector<ll> v;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		
		int vsize = v.size();
		for (int j = 0; j < vsize; j++) {
			auto it = hmap.find(target - (num + v[j]));
			if (it != hmap.end()) {
				if (it->second != j) {
					cout << i + 1 << " " << it->second + 1 << " " << j + 1 << endl;
					return 0;
				}
			}
		}

		v.push_back(num);
		hmap[num] = i;	
	}
	cout << "IMPOSSIBLE" << endl;

	return 0;
}

