#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < s.length(); i += 2) {
        v.push_back(s[i] - '0');
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < (v.size() - 1); i++) {
        cout << v[i] << '+';
    }
    cout << v.back() << endl;

    return 0;
}