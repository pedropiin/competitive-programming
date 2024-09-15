#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll _sieve_size;
bitset<10000010> bs;
vector<int> primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) {
        if (bs[i]) {
            for (ll j = (i * i); j <= _sieve_size; j+= i) {
                bs[j] = 0;
            }
            primes.push_back((int)i);
        }
    }
}

bool isPrime(ll N) {
    if (N <= _sieve_size) {
        return bs[N];
    }
    for (int i = 0; i < (int)primes.size(); i++) {
        if (N % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

ll eulerPhi(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = N;
    while (N != 1 && (PF * PF <= N)) {
        if (N % PF == 0) {
            ans -= ans / PF;
        }
        while (N % PF == 0) {
            N /= PF;
        }
        PF = primes[++PF_idx];
    }
    if (N != 1) {
        ans -= ans / N;
    }
    return ans;
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve(1000000);

    int t;
    cin >> t;
    ll n;
    while (t--) {
        cin >> n;
        cout << eulerPhi(n) << endl;
    }

    return 0;
}                                                                                                                                                               