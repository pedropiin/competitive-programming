#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int requires_two_passes(vector<int> &v, int l) {
	if (v[l] > v[l+1]) return 1;
	return 0;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<int> v(n), pre(n), post(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		pre[v[i]-1] = i;
		post[v[i]-1] = i;
	}

	int cnt = 1;
	for (int i = 0; i < n-1; i++) {
		if (pre[i] > pre[i+1]) cnt++;
	}

	int a, b;
	int x, y;
	int pre_req, post_req;
	for (int i = 0; i < m; i++) {
		cin >> a >> b; a--; b--;

		x = v[a]; y = v[b]; 

		if (x > y) swap(x, y);

		x--; y--;
		swap(post[x], post[y]);
	
		// left of x
		if (x > 0) {
			pre_req = requires_two_passes(pre, x-1);
			post_req = requires_two_passes(post, x-1);
			if (pre_req > post_req) cnt--;
			if (post_req > pre_req) cnt++;
		}
		// right of x
		pre_req = requires_two_passes(pre, x);
		post_req = requires_two_passes(post, x);
		if (pre_req > post_req) cnt--;
		if (post_req > pre_req) cnt++;
		// right of y 
		if (y < n-1) {
			pre_req = requires_two_passes(pre, y);
			post_req = requires_two_passes(post, y);
			if (pre_req > post_req) cnt--;
			if (post_req > pre_req) cnt++;
		}
		if (x != y-1){
			// left of y
			pre_req = requires_two_passes(pre, y-1);
			post_req = requires_two_passes(post, y-1);
			if (pre_req > post_req) cnt--;
			if (post_req > pre_req) cnt++;
		}
		
		swap(pre[x], pre[y]);
		swap(v[a], v[b]);
		
		cout << cnt << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}

