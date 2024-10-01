#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    while (n != 0) {
        map<int, int> game;
        int end = 0;
        ll x = 0;
        int rem = n;
        while (1) {
            x = ((a * ((x * x) % n) % n) + b) % n;
            int &cur_count = game[x];
            cur_count++;
            if (cur_count == 2) {
                rem--;
            } else if (cur_count == 3) {
                break;
            }
        }
        cout << rem << endl;

        cin >> n >> a >> b;
    }    

    return 0;
}