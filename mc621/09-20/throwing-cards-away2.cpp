#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> pow2;
    int i = 0;
    int temp = pow(2, i);

    while (temp < 1000000) {
        pow2.push_back(temp);
        i++;
        temp = pow(2, i);
    }

    int n;
    cin >> n;
    int num_pows = pow2.size();
    
    while (n != 0){
        if (n == 1) {
            cout << 1 << endl;
        } else {
            for (i = 0; i < num_pows; i++) {
                if (n < pow2[i]) {
                    cout << (n - pow2[i - 1]) * 2 << endl;
                    break;
                }
            }
        }

        cin >> n;
    }

    return 0;
}