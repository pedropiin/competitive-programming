#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int sorted(vector<int> &p) {
    int sorted = 1;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] != i + 1) {
            sorted = 0;
            break;
        }
    }
    return sorted;
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        if (sorted) {
            cout << 0 << endl;
        }
        
    }
/*
2 5 1 3 4
5 1 3 2 4
1 2 4 3 5
1 2 3 4 5
*/
    return 0;
}