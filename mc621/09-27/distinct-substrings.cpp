#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007
#define MAXN 100001

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    ll prime = 37;
    ll prime_pow[MAXN];
    prime_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        prime_pow[i] = (prime_pow[i-1] * prime) % MOD;
    }

    unordered_set<int> hset;
    ll count = 0;
    for (int i = 0; i < n; i++) {
        // Rolling Hash algorithm taken from GeeksForGeeks
        ll hash = 0;
        for (int j = i; j < n; j++) {
            int chr = (s[j] - 'a' + 1);
            hash = (hash + chr * prime_pow[j - i]) % MOD;

            if (hset.find(hash) == hset.end()) {
                hset.insert(hash);
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}