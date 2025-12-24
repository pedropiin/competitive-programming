#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool cmp_first(int n, const pair<int, int> &p) {
	return p.first > n;
}

bool cmp_second(const pair<int, int> &p, int n) {
	return p.second < n;
}

bool sort_temp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second < b.second;
}

void solve() {
	int n, d, k; cin >> n >> d >> k;
	vector<pair<int, int>> jobs(k);
	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		jobs[i] = make_pair(a, b);
	}

	sort(jobs.begin(), jobs.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
			return a.first < b.first;
			});

	multiset<int> s;
	int idx = 0;
	int mx = 0, mx_l = -1;
	int mn = 100005, mn_l = -1;
	for (int i = 0; i <= n-d; i++) {
		int l = i+1, r = i+d;
		while (idx < k && jobs[idx].first <= r) {
			s.insert(jobs[idx].second);
			idx++;
		}
		while (!s.empty()) {
			if (*(s.begin()) < l) 
				s.erase(s.begin());
			else break;
		}
		int t = s.size();
		if (t > mx) {
			mx = t;
			mx_l = l;
		} 
		if (t < mn) {
			mn = t;
			mn_l = l;
		}
	}

	cout << mx_l << " " << mn_l << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

