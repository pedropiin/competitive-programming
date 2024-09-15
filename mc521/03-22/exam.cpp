#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, k;
    cin >> t;
    for (int a = 0; a < t; a++) {
        cin >> n >> k;
        int notas[n], freq[n];
        int num;
        for (int i = 0; i < n; i++) {
            cin >> notas[i];
            freq[i] = 0;
        }
        sort(notas, notas + n);

        priority_queue<int> pares;
        // [1, 2, 3, 4, 5, 6, 7, 8]
        // [6, 7, 0, 0, 0, 0, 0, 0]
        
        int par_atual;
        for (int i = 0; i < (n - 1); i++) {
            for (int j = i + 1; j < n; j++) {
                par_atual = notas[i] + notas[j];
                if (pares.size() == k) {
                    if (pares.top() > par_atual) {
                        pares.pop();
                        pares.push(par_atual);
                    }
                } else {
                    pares.push(par_atual);
                }
            }
        }

        cout << pares.top() << endl;
    }
    return 0;
}