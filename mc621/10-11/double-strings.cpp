#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD LONG_LONG_MAX

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int p = 26;
	vector<ll> pow_p(9);
	pow_p[0] = 1;
	for (int i = 1; i < 9; i++) {
		pow_p[i] = (pow_p[i - 1] * p) % MOD;
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<string> strings(n);
		set<ll> string_hashes;
		int temp;
		for (int i = 0; i < n; i++) {
			cin >> strings[i];
			temp = strings[i].size();
			
			ll hash_s = 0;
			for (int j = 0; j < temp; j++) {
				int chr = strings[i][j] - 'a' + 1;
				hash_s = (hash_s + chr * pow_p[j]) % MOD;

			}
			string_hashes.insert(hash_s);
		}
	
		// calculating separate hashes
		string ans = "";
		for (int h = 0; h < n; h++) {
			int possible = 0;
			string temp_string = strings[h];
			int temp_size = temp_string.size();
			for (int i = 1; i < temp_size; i++) {

				ll hash_l = 0;
				ll hash_r = 0;
				for (int j = 0; j < i; j++) {
					int chr = temp_string[j] - 'a' + 1;
					hash_l = (hash_l + chr * pow_p[j]) % MOD;
				}
				for (int j = i; j < temp_size; j++) {
					int chr = temp_string[j] - 'a' + 1;
					hash_r = (hash_r + chr * pow_p[j - i]) % MOD;
				}

				if (string_hashes.count(hash_l) && string_hashes.count(hash_r)) {
					ans += '1';
					possible = 1;
					break;
				}
			}
			if (!possible) {
				ans += '0';
			}
		}
		cout << ans << endl;
	}


	return 0;
}
