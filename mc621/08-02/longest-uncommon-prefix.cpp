// Problem A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < (n - 1); i++) {
        for (int l = (n - i - 1); l >= 0; l--) {
            int valid = 1;
            for (int j = 0; j < l; j++){
                if (s[j] == s[j + i + 1]) {
                    valid = 0;
                    break;
                }
            }
            if (valid || l == 0) {
                cout << l << endl;
                break;
            } 
        }
    }

    return 0;
}