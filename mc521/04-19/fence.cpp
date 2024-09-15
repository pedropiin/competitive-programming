#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, temp;
    cin >> n >> k;
    vector<int> v, somas;

    cin >> temp;
    v.push_back(temp);
    somas.push_back(temp);
    for (int i = 1; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
        somas.push_back(temp + somas[i - 1]);
    }

    int menor, i_menor = 1;
    for (int i = (k - 1); i < n; i++) {
        if ((i - k) < 0) {
            menor = (somas[i]);
            i_menor = 1;
        } else {
            if ((somas[i] - somas[i - k]) < menor) {
                menor = (somas[i] - somas[i - k]);
                i_menor = i - k + 2;
            }
        }
    }

    cout << i_menor << endl;

    return 0;
}