#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int left = 0;
    int right = n;
    while (left < (right - 1)) {
        int mid = left + (right - left) / 2;

        cout << "? " << (left + 1) << " " << right << endl;
        int sec_big;
        cin >> sec_big;
        sec_big--; // adjusting index

        int temp;
        int valid = 0;
        if (sec_big < mid) {
            if ((left + 1) < mid) {
                valid = 1;
                cout << "? " << (left + 1) << " " << mid << endl;
                cin >> temp;
                temp--; // adjusting index
            }
            if (valid && temp == sec_big) {
                right = mid;
            } else {
                left = mid;
            }
        } else {
            if ((mid + 1) < right) {
                valid = 1;
                cout << "? " << (mid + 1) << " " << right << endl;
                cin >> temp;
                temp--; // adjusting index
            }
            if (valid && temp == sec_big) {
                left = mid;
            } else {
                right = mid;
            }
        }
    }

    cout << "! " << right << endl;

    return 0;
}