#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string minWindow(string s, string t) {
    int m = s.size(), n = t.size();
    unordered_map<char, int> needed_freq;
    for (char c : t) needed_freq[c]++;
    int needed = needed_freq.size();

    vector<pair<char, int>> v;
    for (int i = 0; i < m; i++) {
        if (needed_freq[s[i]] != 0) {
            v.push_back({s[i], i});
        }
    }
    int vsz = v.size();

    unordered_map<char,int> freq;
    int cnt = 0, mn = INT_MAX, ans_l = 0, ans_r = 0, l = 0;

    for (int i = 0; i < vsz; i++) {
        pair<char, int> curr = v[i];
        if (freq[curr.first] < needed_freq[curr.first]) {
            freq[curr.first]++;
            if (freq[curr.first] == needed_freq[curr.first]) cnt++;

            if (cnt == needed) {
                while (freq[v[l].first] > needed_freq[v[l].first]) {
                    freq[v[l].first]--;
                    l++;
                }
                if (mn > (curr.second - v[l].second + 1)) {
                    ans_l = v[l].second;
                    ans_r = curr.second;
                    mn = (curr.second - v[l].second + 1);
                }
            }
        } else {
            freq[curr.first]++;
            if (cnt == needed) {
                while (cnt == needed) {
                    freq[v[l].first]--;
                    if (freq[v[l].first] < needed_freq[v[l].first]) cnt--;
                    l++;

                    if (cnt == needed && mn > (curr.second - v[l].second + 1)) {
                        ans_l = v[l].second;
                        ans_r = curr.second;
                        mn = (curr.second - v[l].second + 1);
                    }
                }
            }
        }
    }

    if (mn == INT_MAX) return "";
    return s.substr(ans_l, mn);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s, t; cin >> s >> t;
	cout << minWindow(s, t) << endl;

	return 0;
}

