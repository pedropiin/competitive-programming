#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sum_square_digits(ll n) {
    ll sum = 0;
    while (n >= 10) {
        sum += pow((n % 10), 2);
        n = n / 10;
    }
    sum += pow(n, 2);
    return sum;
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int num_test = 1;
    while (t--) {
        ll n;
        cin >> n;

        set<int> squares;
        ll sum = n;
        while (1) {
            sum = sum_square_digits(sum);

            if (sum == 1) {
                cout << "Case #" << num_test << ": " << n << " is a Happy number." << endl;
                break;
            }
            if (squares.find(sum) != squares.end()) {
                cout << "Case #" << num_test << ": " << n << " is an Unhappy number." << endl;
                break;
            }
            squares.insert(sum);
        }
        num_test++;
    }

    return 0;
}