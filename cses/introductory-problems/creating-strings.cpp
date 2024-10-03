#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void permutations(string &s, int p, int n, set<string> &perms) {
    if (p == (n - 1)) {
        perms.insert(s);
    } else {
        for (int i = p; i < n; i++) {
            swap(s[i], s[p]);
            permutations(s, (p + 1), n, perms);
            swap(s[i], s[p]);
        }
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    set<string> perms;
    permutations(s, 0, n, perms);
    cout << perms.size() << endl;
    for (string t : perms) {
        cout << t << endl;
    }

    return 0;
}