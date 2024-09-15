#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    ll k;
    cin >> t;
    string s;
    for (int _ = 0; _ < t; _++) {
        queue<int> fila_pos_zero;
        int i_zero, pos_stop_swap = 0;
        ll count_moves;
        cin >> n >> k;
        cin >> s;
        count_moves = k;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                fila_pos_zero.push(i);
            }
        }
        char temp;
        while (count_moves > 0 && fila_pos_zero.size() > 0) {
            i_zero = fila_pos_zero.front();
            fila_pos_zero.pop();
            if ((i_zero - pos_stop_swap) <= count_moves) {
                s[i_zero] = '1';
                s[pos_stop_swap] = '0';
                count_moves -= (i_zero - pos_stop_swap);
                if (count_moves == 0) {
                    break;
                }
            } else {
                s[i_zero] = '1';
                s[i_zero - count_moves] = '0';
                count_moves = 0;
                break;
            }
            pos_stop_swap++;
        }
        cout << s << endl;
    }

    return 0;
}