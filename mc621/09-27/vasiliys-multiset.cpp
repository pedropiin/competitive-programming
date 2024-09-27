#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    unordered_map<int, int> hmap;
    char query;
    int n;
    while (q--) {
        cin >> query >> n;
        switch (query) {
            case '+':
                if (hmap.find(n) == hmap.end()) {
                    hmap.insert(pair<int, int>(n, 1));
                } else {
                    hmap[n]++;
                }
                break;
            case '-':
                hmap[n]--;
                if (hmap[n] == 0) {
                    hmap.erase(n);
                }
                break;
            case '?':
                int xor_max = 0;
                for (auto& it: hmap) {
                    xor_max = max(xor_max, it.first ^ n);
                }
                cout << xor_max << endl;
                break;
        }
    }


    return 0;
}