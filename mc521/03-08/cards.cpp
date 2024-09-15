#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<int> v(5);

    for (int i = 0; i < 5; i++) {
        v[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        switch(s[i]) {
            case 'e':
                v[0]++;
                break;
            case 'n':
                v[1]++;
                break;
            case 'o':
                v[2]++;
                break;
            case 'r':
                v[3]++;
                break;
            case 'z':
                v[4]++;
                break;
        }
    }

    int max, min, num;
    if (v[4] >= v[1]) {
        max = v[4];
        min = v[1];
        num = 0;
    } else {
        max = v[1];
        min = v[4];
        num = 1;
    }

    if (num == 1) {
        for (int i = 0; i < max; i++) {
            cout << "1 ";
        }
        v[0] -= max;
        v[2] -= max;
        v[3] -= max;
        v[4] -= max;
        for (int i = 0; i < min; i++) {
            cout << "0 ";
        }
    } else {
        for (int i = 0; i < min; i++) {
            cout << "1 ";
        }
        v[0] -= min;
        v[2] -= min;
        v[3] -= min;
        v[4] -= min;
        for (int i = 0; i < max; i++) {
            cout << "0 ";
        }
    }
    cout << endl;

    return 0;
}