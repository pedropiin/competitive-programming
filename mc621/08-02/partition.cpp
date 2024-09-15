#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> div;
    for (int i = 1; i <= (sqrt(m) + 1); i++) {
        if ((m % i) == 0) {
            div.push_back(i);
            div.push_back(m / i);
        }
    }

    sort(div.begin(), div.end());
    
    double min = (double)m / (double)n;
    for (int i = div.size() - 1; i > 0; i--) {
        if (div[i] <= min) {
            cout << div[i] << endl;
            break;
        }
    }

    return 0;
}