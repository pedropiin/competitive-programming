#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> maps(26, 0);
        vector<int> mapt(26, 0);
        for (int i = 0; i < s.size(); i++) {
            maps[s[i] - 'a']++;
            mapt[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (maps[i] != mapt[i]) return false;
        }
        return true;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;

    Solution solve;
    cout << solve.isAnagram(s, t) << endl;

    return 0;
}