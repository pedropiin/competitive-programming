#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> leftmost_smaller(n, -1);

    stack<pair<int, int>> st;
    st.push({heights[n-1], n-1});
    for (int i = n-2; i >= 0; i--) {
        while (st.size() > 0 && st.top().first > heights[i]) {
            leftmost_smaller[st.top().second] = i;
            st.pop();
        }
        st.push({heights[i], i});
    }

    vector<int> rightmost_smaller(n, -1);
    stack<pair<int, int>> st1;
    st1.push({heights[0], 0});
    for (int i = 1; i < n; i++) {
        while (st1.size() > 0 && st1.top().first > heights[i]) {
            rightmost_smaller[st1.top().second] = i;
            st1.pop();
        }
        st1.push({heights[i], i});
    }

    int mx = 0;
    int l, r;
    for (int i = 0; i < n; i++) {
        l = (leftmost_smaller[i] >= 0) ? leftmost_smaller[i] : -1;
        r = (rightmost_smaller[i] >= 0) ? rightmost_smaller[i] : n;
        mx = max(mx, heights[i] * (r-l - 1));
    }

    return mx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> heights(n);
	for (int i = 0; i < n; i++) cin >> heights[i];

	cout << largestRectangleArea(heights) << endl;

	return 0;
}

