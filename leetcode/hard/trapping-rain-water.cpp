#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int trap(vector<int>& height) {
    int n = height.size();
    stack<pair<int, int>> st;
    int ans = 0;

    for (int i = 0; i < n-1; i++) {
        int curr = height[i], next = height[i+1];
        if (curr > next) {
            st.push({curr-next, i});
        } else if (curr < next) {
            int diff = next-curr;
            while (st.size() > 0 && diff > 0) {
                int dist = i - st.top().second;
                if (diff >= st.top().first) {
                    ans += dist * st.top().first;
                    diff -= st.top().first;
                    st.pop();
                } else {
                    ans += dist * diff;
                    st.top().first -= diff;
                    diff = 0;
                }
            }
        }
    }

    return ans;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) cin >> heights[i];

    cout << trap(heights) << endl;

    return 0;
}
