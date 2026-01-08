#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();

    deque<int> window;
    deque<int> dq;
    for (int i = 0; i < k; i++) {
        window.push_back(nums[i]);
        while (!dq.empty() && dq.back() < nums[i]) dq.pop_back();
        dq.push_back(nums[i]);
    }
    vector<int> ans; ans.push_back(dq.front());
    for (int i = k; i < n; i++) {
        window.push_back(nums[i]);
        while (!dq.empty() && dq.back() < nums[i]) dq.pop_back();
        dq.push_back(nums[i]);
        if (!dq.empty() && dq.front() == window.front()) dq.pop_front();
        window.pop_front();
        ans.push_back(dq.front());
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> ans = maxSlidingWindow(nums, k);
    for (int elem : ans) cout << elem << " ";
    cout << endl;

    return 0;
}
