#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX_IN 200001

int soma_digitos(int n) {
    int temp = n, result = 0;
    while (temp > 9) {
        result += temp % 10;
        temp = temp / 10;
    }   
    result += temp;
    return result;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v(MAX_IN + 1);
    int num_digitos;
    for (int i = 1; i < MAX_IN; i++) {
        if (i < 10) {
            v[i] = (i * (i + 1)) / 2;
        } else {
            v[i] = v[i - 1] + soma_digitos(i);
        }
    }

    int t, n;
    cin >> t;
    for (int a = 0; a < t; a++) {
        cin >> n;
        cout << v[n] << endl;
    }

    return 0;
}