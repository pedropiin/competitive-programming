#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int minEatingSpeed(vector<int>& piles, int h) {
    long long int r = 0;
    int n = piles.size();
    for (int i = 0; i < n; i++) r += (long long int)piles[i];

    long long int l = 1, m;
    while (l <= r) {
        m = (r-l)/2 + l;

        int flag = 1, cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (piles[i]/m)+ ((piles[i] % m == 0) ? 0 : 1);
            if (cnt > h) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            r = m-1;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, h; cin >> n >> h;
	vector<int> piles(n);
	for (int i = 0; i < n; i++) cin >> piles[i];

	cout << minEatingSpeed(piles, h) << endl;

	return 0;
}

