#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    if (n1 == 0 || n2 == 0) {
        return vector<int>{};
    }

    unordered_map<int, int> idxs1;
    for (int i = 0; i < n1; i++) {
        idxs1[nums1[i]] = i;
    }

    vector<pair<int, int>> v(n2);
    for (int i = 0; i < n2; i++) {
        if (idxs1.count(nums2[i]) > 0) {
            v[i] = {nums2[i], idxs1[nums2[i]]};
        } else {
            v[i] = {nums2[i], -1};
        }
    }

    vector<int> ans(n1, -1);
    stack<pair<int, int>> st;
    st.push(v[0]);
    for (int i = 1; i < n2; i++) {
        while (st.size() > 0 && st.top().first < v[i].first) {
            if (st.top().second != -1) {
                ans[st.top().second] = v[i].first;
            }
            st.pop();
        }
        st.push(v[i]);
    }

    return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n1, n2; cin >> n1 >> n2;
	vector<int> nums1(n1), nums2(n2);
	for (int i = 0; i < n1; i++) cin >> nums1[i];
	for (int i = 0; i < n2; i++) cin >> nums2[i];

	cout << nextGreaterElement(nums1, nums2) << endl;

	return 0;
}

