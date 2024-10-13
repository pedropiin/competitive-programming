#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX INT_MAX 

// algorithm idea taken from https://algorithmist.com/wiki/UVa_11258_-_String_Partition
int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		vector<ll> dp((n + 1), 0);
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				dp[i] = dp[i + 1];
			} else {
				ll sum = 0;
				for (int j = i; j < n; j++) {
					sum *= 10;
					sum += s[j] - '0';
					if (sum > MAX) {
						break;
					}
					// note that here 'j' refers to the j-th digit in a 0-indexed array, 
					// but in the dp array, it refers to the max using only j digits, 
					// that is, excluding the digit currently under analysis.	
					// Therefore, we need to use (j + 1) when acessing the dp array, 
					// meaning that we are also considering the j-th digit in the sum.
					dp[j + 1] = max(dp[j + 1], dp[i] + sum);
				}
			}
		}
		cout << dp[n] << endl;
	}

	return 0;
}
