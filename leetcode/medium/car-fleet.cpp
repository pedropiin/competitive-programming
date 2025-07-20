#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first <= b.first;
        });
        int count = 0; 
        float m = 0;
        for (int i = n - 1; i >= 0; i--) {
            float tmp = (float)(target - v[i].first) / v[i].second;
            if (tmp > m) {
                count++;
                m = tmp;
            }
        }

        return count;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    Solution solve;
    cout << solve.carFleet(target, position, speed) << endl;

    return 0;
}