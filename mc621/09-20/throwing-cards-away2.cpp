#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n != 0){
        deque<int> dq(n);
        for (int i = 0; i < n; i++) {
            dq[i] = i+1;
        }

        while (dq.size() > 1) {
            dq.pop_front();
            dq.push_back(dq[0]);
            dq.pop_front();
        }
        cout << dq[0] << endl;
        cin >> n;
    }

    return 0;
}