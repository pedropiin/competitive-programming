#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
            while (s.size() != 0 && s.top().first <= temperatures[i]) {
                count += s.top().second + 1;
                s.pop();
            }
            if (s.size() == 0) ans[i] = 0;
            else ans[i] = count + 1;
            s.push({temperatures[i], count});
        }
        return ans;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    Solution solve;
    cout << solve.dailyTemperatures(temperatures) << endl;

    return 0;
}