#include <bits/stdc++.h>

#define ALPHA_SIZE 26

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int len = s.size();
    int back = 0;
    int front = 0;
    ll ans = 0;
    vector<int> freq(ALPHA_SIZE, 0);
    while (front < len) {
        int i_cur_char = s[front] - 'a';
        freq[i_cur_char]++;

        while (freq[i_cur_char] > 1) {
            int i_back_char = s[back] - 'a';
            freq[i_back_char]--;
            back++;
        }
        ans += front - back + 1;

        front++;
    }

    cout << ans << endl;

    return 0;
}