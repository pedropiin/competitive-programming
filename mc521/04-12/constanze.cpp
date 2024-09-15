#include <bits/stdc++.h>

#define MOD_MAX 1000000007

using namespace std;

typedef long long ll;


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size(), possivel = 1;
    vector<int> vdp(n + 1);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            possivel = 0;
            break;
        }
    }
    if (possivel) {
        vdp[0] = 1;
        vdp[1] = 1;
        for (int i = 2; i <= n; i++) {
            vdp[i] = vdp[i - 1];
            if (s[i - 1] == 'n' && s[i - 2] == 'n') {
                vdp[i] = (vdp[i] + vdp[i - 2]) % MOD_MAX;
            } else if (s[i - 1] == 'u' && s[i - 2] == 'u') {
                vdp[i] = (vdp[i] + vdp[i - 2]) % MOD_MAX;
            }
        }
        cout << vdp[n] << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}