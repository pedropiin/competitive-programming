#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, "", 0, 0, n);
        return ans;
    }

    void dfs(vector<string> &ans, string curr, int open, int close, int n) {
        if (open == n && close == n) {
            ans.push_back(curr);
            return;
        }
        if (open < n) {
            dfs(ans, curr + "(", open + 1, close, n);
        }
        if (close < open) {
            dfs(ans, curr + ")", open, close + 1, n);
        }
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 8;

    Solution solve;
    cout << solve.generateParenthesis(n) << endl;

    return 0;
}