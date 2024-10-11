#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int bin_search(vector<int> &adj_list, int n) {
    int l = 0;
    int r = adj_list.size();

    while (l <= r) {
        int m = (l + r) / 2;
        if (adj_list[m] == n) {
            return m;
        } else if (adj_list[m] > n) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return l;
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> teste = {3, 5, 8, 9, 12, 15};
    cout << bin_search(teste, 12) << endl;

    return 0;
}