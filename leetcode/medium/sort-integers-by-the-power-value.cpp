#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int calc(int x) {
    int count = 0;
    while (x != 1) {
        if (x % 2 == 0) x = x >> 1;
        else x = 3*x + 1;
        count++;
    }
    return count;
}

int getKth(int lo, int hi, int k) {
    int n = hi - lo + 1;
    priority_queue<pair<int, int>> pq;
    int x;
    for (int i = lo; i <= hi; i++) {
        x = calc(i);
        if (pq.size() < k) pq.push({x, i});
        else {
            if (pq.top().first > x) {
                pq.pop();
                pq.push({x, i});
            }
        }
    }

    return pq.top().second;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int lo, hi, k; cin >> lo >> hi >> k;
    cout << getKth(lo, hi, k) << endl;

    return 0;
}
