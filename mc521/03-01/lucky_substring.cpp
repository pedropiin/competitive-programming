#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n4 = 0, n7 = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '4') {
            n4++;
        } else if (s[i] == '7') {
            n7++;
        }
    }

    if (n4 == 0 && n7 == 0) {
        cout << "-1" << endl;
    } else if (n4 == n7 || n4 > n7) {
        cout << '4' << endl;
    } else if (n4 < n7) {
        cout << '7' << endl;
    }
    
    return 0;
}