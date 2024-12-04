#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];

    int count = 0;
    for (int i = 0 ; i < (n - 1); i++) {
        if (v[i] > v[i + 1]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}