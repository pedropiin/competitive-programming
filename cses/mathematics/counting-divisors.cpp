#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        int count = 0; // considering the number itself and 1
        for (int pos = 1; pos <= sqrt(num); pos++) {
            if ((num % pos) == 0) {
                if ((num / pos) == pos) {
                    count++;
                } else {
                    count += 2;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}
