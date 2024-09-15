#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, temp;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    int count = 1, max_len = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] >= v[i - 1]) {
            count++;
        } else {
            if (count > max_len) {
                max_len = count;
            }
            count = 1;
        }
    }

    cout << max(max_len, count) << endl;

    return 0;
}