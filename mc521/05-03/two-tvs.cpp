#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> s(n), e(n), count_s(n), count_e(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
        count_s[s[i]]++;
        count_e[e[i]]++;
        if (count_s[s[i]] > 2) {
            cout << "NO" << endl;
        } else if () {

        }
    }

    return 0;
}