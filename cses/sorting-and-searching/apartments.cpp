#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> wish(n);
    vector<int> ap(m);

    for (int i = 0; i < n; i++) {
        cin >> wish[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> ap[i];
    }

    sort(wish.begin(), wish.end());
    sort(ap.begin(), ap.end());


    vector<int> freq(m, 1);
    int count = 0, stop = 0;
    for (int i = 0; i < n; i++) {
        for (int j = stop; j < m; j++) {
            if (freq[j] == 0) {
                continue;
            }
            if (ap[j] < (wish[i] - k)) {
                freq[j] = 0;
            } else if (ap[j] > (wish[i] + k)) {
                stop = j;
                break;
            } else {
                count++;
                freq[j] = 0;
                stop = j + 1;
                break;
            }
        }
    }

    cout << count << endl;

    return 0;
}