#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, num, found;
    set<int> s;
    while (1) {
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            cin >> num;
            s.insert(num);
        }

        found = 0;
        for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
            for (set<int>::iterator it2 = s.begin(); it != s.end(); it2++) {
                for (set<int>::iterator it3 = s.begin(); it3 != s.end(); it3++) {
                    if (*it == *it2 || *it == *it3 || *it2 == *it3) {
                        continue;
                    }
                    int result = *it2 + *it3 - *it;
                    if (s.count(result) == 1 || s.count(abs(result))) {
                        cout << *it << endl;
                        found = 1;
                    }
                }
            }
        }
        if (found == 0) {
            cout << "no solution" << endl;
        }
    }
    return 0;
}