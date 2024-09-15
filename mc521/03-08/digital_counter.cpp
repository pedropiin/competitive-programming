#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
*   a   *
b       c
*   d   *
e       f
*   g   *
*/

/*
passar por todos os caracteres.
tem o da iteração?
    sim
        passa pro proximo
    não
        
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v(10);
    v[0] = "abcefg";
    v[1] = "cf";
    v[2] = "acefg";
    v[3] = "acdfg";
    v[4] = "bcdg";
    v[5] = "abdfg";
    v[6] = "abdefg";
    v[7] = "acf";
    v[8] = "abcdefg";
    v[9] = "abcdfg";

    string s;
    cin >> s;
    string num, completo = "abcdefg";
    int count1 = 1, count2 = 1;
    for (int i = 0; i < s.length(); i++) {
        num = s[0];

    }

    return 0;
}