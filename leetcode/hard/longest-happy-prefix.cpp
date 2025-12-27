#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string longestPrefix(string s) {
    int n = s.length();
    vector<int> lps(n, 0);
    int len = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
        } else {
            if (len == 0) lps[i] = 0;
            else {
                while (len > 0 && s[i] != s[len]) len = lps[len-1];
                if (s[i] == s[len]) {
                    len++;
                }
                lps[i] = len;
            }
        }
    }
    int longest = lps[n-1];
    string ans = s.substr(0, longest);
    return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s; cin >> s;
	cout << longestPrefix(s) << endl;

	return 0;
}

