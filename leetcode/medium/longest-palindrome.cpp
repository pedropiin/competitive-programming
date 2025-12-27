#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void expand(int l, int r, pair<int, int> &idxs, string &s) {
    int n = s.length();
    while (l >= 0 && r < n && s[l] == s[r]) {
        l--;
        r++;
    }
    idxs.first = l+1;
    idxs.second = r-1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s; cin >> s;
	int ans_l = 0, ans_r = 0;
    pair<int, int> idxs = make_pair(0, 0);
    int n = s.length();
    for (int i = 0; i < n-1; i++) {
        expand(i, i, idxs, s);
        if ((idxs.second - idxs.first) > (ans_r - ans_l)) {
            ans_l = idxs.first;
            ans_r = idxs.second;
        }
        idxs.first = 0; idxs.second = 0;
        expand(i, i+1, idxs, s);
        if ((idxs.second - idxs.first) > (ans_r - ans_l)) {
            ans_l = idxs.first;
            ans_r = idxs.second;
        }
        idxs.first = 0; idxs.second = 0;
    }
    string ans = "";
    for (int i = ans_l; i <= ans_r; i++) ans += s[i];
	cout << ans << endl;

	return 0;
}

