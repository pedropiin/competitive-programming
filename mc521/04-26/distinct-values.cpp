#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int i_esquerda = 0, i_direita = 0, num_elems = 0;
    ll count = 0;
    map<int, int> freq;
    while (i_esquerda < n) {
        while (i_direita < n) {
            if (freq[v[i_direita]] == 0 && (num_elems + 1) > k) {
                break;
            }
            if (freq.find(v[i_direita]) == freq.end() || freq[v[i_direita]] == 0) {
                freq[v[i_direita]] = 1;
                num_elems++;
            } else {
                freq[v[i_direita]]++;
            }
            i_direita++;
        }
        count += i_direita - i_esquerda;
        if (freq[v[i_esquerda]] == 1) {
            num_elems--;
        }
        freq[v[i_esquerda]]--;
        i_esquerda++;
    }

    cout << count << endl;

    return 0;
}