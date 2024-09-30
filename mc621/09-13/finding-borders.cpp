#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.length();

	int p = 31;
	vector<ll> pow_p(n);
	pow_p[0] = 1;
	for (int i = 1; i < n; i++) {
		pow_p[i] = (pow_p[i-1] * p) % MOD;
	}

	ll hash_prefix = 0;
	ll hash_suffix = 0;
	for (int i = 0; i < (n - 1); i++) {
		int chr_left = s[i] - 'a' + 1;
		int chr_right = s[n - i - 1] - 'a' + 1;

		hash_prefix = (hash_prefix + chr_left * pow_p[i]) % MOD;
		hash_suffix = (hash_suffix * p + chr_right) % MOD;

		if (hash_prefix == hash_suffix) {
			cout << i + 1 << " ";
		}
	}
    cout << endl;

    return 0;
}   
