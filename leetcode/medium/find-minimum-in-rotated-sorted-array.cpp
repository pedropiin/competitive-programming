#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int findMin(vector<int>& nums) {
    int n = nums.size();

    int l = 0, r = n-1;
    while (l < r) {
        int m = (r-l)/2 + l;

        if (nums[m] >= nums[l] && nums[m] <= nums[r]) {
            return nums[l];
        }
        if (m > 0 && nums[m-1] > nums[m]) {
            return nums[m];
        }
        if (m < n-1 && nums[m] > nums[m+1]) {
            return nums[m+1];
        }
        if (nums[m] < nums[l]) {
            r = m-1;
        } else if (nums[m] > nums[r]) {
            l = m+1;
        }
    }
    return nums[l];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	cout << findMin(nums) << endl;

	return 0;
}

