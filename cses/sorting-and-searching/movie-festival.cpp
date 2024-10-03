#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), [](const pair<int, int> &left, const pair<int, int> &right) {
		return left.second < right.second;
	});

	int count = 0;
	int next = 0;
	for(int i = 0; i < n; i++) {
		if (v[i].first >= next)	{
			next = v[i].second;
			count++;
		}
	}
	cout << count << endl;

	return 0;
}
