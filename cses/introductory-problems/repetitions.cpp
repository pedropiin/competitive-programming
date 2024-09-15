#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    string dna;
    cin >> dna;
 
    char c_anal = dna[0];
    int seq = 1, max = 1;
    for (int i = 1; i < dna.size(); i++) {
        if (dna[i] == c_anal) {
            seq++;
            if (seq > max) {
                max = seq;
            }
        } else {
            c_anal = dna[i];
            seq = 1;
        }
    }
 
    cout << max << endl;
 
    return 0;
}

