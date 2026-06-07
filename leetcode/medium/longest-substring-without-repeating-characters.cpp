#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_map<char, int> m;
    int l = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        if (m[s[i]] == 0) {
            m[s[i]] = 1;
        } else {
            mx = max(mx, i-l);
            while (s[l] != s[i]) {
                m[s[l]] = 0;
                l++;
            }
            l++;
        }
    }
    mx = max (mx, n-l);

    return mx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s; cin >> s;
	cout << lengthOfLongestSubstring(s) << endl;

	return 0;
}

