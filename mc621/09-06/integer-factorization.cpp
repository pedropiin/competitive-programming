#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX_FACS 100000

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll num;
    cin >> num;
    while (num) {
        int count  = 0;
        vector<ll> factors(MAX_FACS, 0);
        vector<ll> powers(MAX_FACS, 0);

        // Ideia de algoritmo retirada do site geeks for geeks, disponível em: https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
        if (num % 2 == 0) {
            factors[count] = 2;
            while (num % 2 == 0) {
                powers[count]++;
                num /= 2; 
            }
            count++;
        }

        for (int i = 3; i <= sqrt(num); i = i+2) {
            if (num % i == 0) {
                factors[count] = i;
                while (num % i == 0) {
                    powers[count]++;
                    num /= i;
                }
                count++;

            }
        }
        if (num > 2) {
            factors[count] = num;
            powers[count]++;
            count++;
        }

        for (int i = 0; i < count; i++) {
            cout << factors[i] << "^" << powers[i] << " ";
        }
        cout << endl;

        cin >> num;
    }

    return 0;
}