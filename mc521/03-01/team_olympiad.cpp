#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, num, c1 = 0, c2 = 0, c3 = 0;
    vector <int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
        if (num == 1) {
            c1++;
        } else if (num == 2) {
            c2++;
        } else if (num == 3) {
            c3++;
        }
    }

    int num_times = min({c1, c2, c3});
    cout << num_times << endl;

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < num_times; i++) {
        for (int j = 0; j < n; j++) {
            if (v[j] == 1 && a == 0) {
                cout << j + 1 << ' ';
                a = 1;
                v[j] = 0;
            } else if (v[j] == 2 && b == 0) {
                cout << j + 1 << ' ';
                b = 1;
                v[j] = 0;
            } else if (v[j] == 3 && c == 0) {
                cout << j + 1 << ' ';
                c = 1;
                v[j] = 0;
            }
        }
        a = 0;
        b = 0;
        c = 0;
        cout << endl;
    }


    return 0;
}
