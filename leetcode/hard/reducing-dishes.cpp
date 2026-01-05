#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int maxSatisfaction(vector<int>& satisfaction) {
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());

    int first_gez_idx = -1;
    for (int i = 0; i < n; i++) {
        if (satisfaction[i] >= 0) {
            first_gez_idx = i; break;
        }
    }

    if (first_gez_idx == -1) return 0;

    ll ans = 0;
    ll elem_sum = 0;
    for (int i = first_gez_idx; i < n; i++) {
        ans += satisfaction[i] * (i-first_gez_idx+1);
        elem_sum += satisfaction[i];
    }

    if (first_gez_idx <= 0) return ans;

    ll temp;
    for (int i = first_gez_idx-1; i >= 0; i--) {
        elem_sum += satisfaction[i];
        temp = ans + elem_sum;
        if (temp <= ans) break;
        ans = temp;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> satisfaction(n);
    for (int i = 0; i < n; i++) cin >> satisfaction[i];

    cout << maxSatisfaction(satisfaction) << endl;

    return 0;
}
