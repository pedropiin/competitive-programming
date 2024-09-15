#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s1, s2;
    cin >> s1;
    cin >> s2;

    n = s1.length();

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    char c1, c2;
    int diff = 0;
    for (int i = 0; i < n; i++) {
        c1 = s1.at(i);
        c2 = s2.at(i);
        if (c1 == c2) {
            continue;
        } else if (c1 < c2) {
            cout << "-1" << endl;
            diff = 1;
            break;
        } else {
            cout << "1" << endl;
            diff = 1;
            break;
        }
    }

    if (diff == 0) {
        cout << "0" << endl;
    }

    return 0;
}