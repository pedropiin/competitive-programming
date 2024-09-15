#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ALFABETO 26
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    string s;
    cin >> s;
    int n = s.size();
    int count[ALFABETO] = {0};
 
    for (int i = 0; i < n; i++) {
        count[int(s[i]) - 65]++;
    }
 
    int impares = 0, possivel = 1;
    char impar;
    for (int i = 0; i < ALFABETO; i++) {
        if (count[i] % 2 != 0) {
            impares++;
            impar = i + 65;
            if (impares > 1) {
                possivel = 0;
                break;
            }
        }
    }
    
    if (possivel) {
        vector <char> v;
        for (int i = 0; i < ALFABETO; i++) {
            if (i != (int(impar) - 65)) {
                for (int j = 0; j < count[i] / 2; j++) {
                    v.push_back(i + 65);
                    cout << char(i + 65);
                }
            } else {
                continue;
            }
        }
        if (impares) {
            for (int i = 0; i < count[int(impar) - 65]; i++) {
                cout << char(impar);
            }
        }
        for (int i = v.size() - 1; i >= 0; i--) {
            cout << v[i];
        }
        cout << endl;
    } else {
        cout << "NO SOLUTION" << endl;
    }
 
    return 0;
}

