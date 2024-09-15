#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q, n;
    cin >> q;
    for (int a = 0; a < q; a++) {
        cin >> n;
        int p[n], l_pre[n], l_pos[n], d[n];
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            l_pre[i] = i + 1;
            l_pos[i] = i + 1;
            d[i] = 0;
        }
        int count = 0, num_completos = 0, completos[n];
        for (int i = 0; i < n; i++) {
            completos[i] = 0;
        } 
        while (num_completos != n) {
            for (int i = 0; i < n; i++) {
                l_pos[p[i] - 1] = l_pre[i];
            }
            count++;
            for (int i = 0; i < n; i++) {
                if (l_pos[i] == (i + 1) && completos[i] == 0) {
                    d[i] = count;
                    num_completos++;
                    completos[i] = 1;
                }
            }
            for (int i = 0; i < n; i++) {
                l_pre[i] = l_pos[i];
            }
        }

        for (int i = 0; i < n; i++) {
            cout << d[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}