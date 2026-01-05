#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int tallestBillboard(vector<int>& rods) {
    unordered_map<int, int> diff_map;
    diff_map[0] = 0;

    for (int rod : rods) {
        unordered_map<int, int> checkpoint_map(diff_map);
        for (auto entry : checkpoint_map) {
            int og_diff = entry.first;
            int left_height = entry.second;
            diff_map[og_diff + rod] = max(diff_map[og_diff + rod], left_height + rod);

            int right_height = left_height - og_diff + rod;
            if (right_height > left_height) {
                diff_map[right_height - left_height] = max(diff_map[right_height - left_height], right_height);
            } else {
                diff_map[left_height - right_height] = max(diff_map[left_height - right_height], left_height);
               }
            }
        }

    return diff_map[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> rods(n);
    for (int i = 0; i < n; i++) cin >> rods[i];

    cout << tallestBillboard(rods) << endl;

    return 0;
}
