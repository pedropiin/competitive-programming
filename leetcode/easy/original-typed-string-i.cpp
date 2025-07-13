#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    int possibleStringCount(string word) {
        vector<int> freq(26, 0);
        int sz = word.size();
        int ans = 0, temp;
        for (int i = 0; i < sz; i++) {
            temp = word[i] - 'a';
            freq[temp]++;
            if (freq[temp] > 1 && word[i - 1] == word[i]) ans++;
        } 
        return ans + 1;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string word;
    cin >> word;

    Solution solve;
    cout << solve.possibleStringCount(word) << endl;

    return 0;
}