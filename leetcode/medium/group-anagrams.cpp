#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        int mod = 1000000007;
        map<long long int, int> m;
        int idx = 1;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            long long int hash = 1;
            string it_string = strs[i];
            int sz = it_string.size();
            for (int j = 0; j < sz; j++) {
                hash = (hash * primes[it_string[j] - 'a']) % mod;
            }            
            if (m[hash] == 0) {
                ans.push_back(vector<string>());
                ans[idx - 1].push_back(it_string);
                m[hash] = idx++;
            } else {
                ans[m[hash] - 1].push_back(it_string);
            }
        }
        return ans;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) cin >> strs[i];

    cout << Solution.groupAnagrams(strs) << endl;

    return 0;
}