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

    sort(v.begin(), v.end());
    int val = v[n/2];

    ll sum = 0;
    for (int i = 0; i < n; i++) 
        sum += abs(v[i] - val);

    cout << sum << endl;

    return 0;
}