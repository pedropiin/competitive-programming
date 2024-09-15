#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, t;
    vector<int> a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        b.push_back(t);
    }

    int count = 0, max = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[j] % a[i] == 0) {
                if (b[j] / a[i] > max) {
                    max = b[j] / a[i];
                    count = 1;
                } else if (b[j] / a[i] == max) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}