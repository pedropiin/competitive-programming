#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b, n;
        cin >> a >> b >> n;
        
        int c = a ^ b;
        vector<int> v {a, b, c};
        cout << v[n % 3] << endl;
    }

    return 0;
}