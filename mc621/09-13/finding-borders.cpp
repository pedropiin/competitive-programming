#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.length();

    hash<char> hasher;
    size_t lhash = 0;
    size_t rhash = 0;
    for (int i = 0; i < (n - 1); i++) {
        lhash += hasher(s[i]);
        rhash += hasher(s[n - i - 1]);

        if (lhash == rhash) {
            cout << (i + 1) << " ";
        }
    }

    cout << endl;

    return 0;
}   