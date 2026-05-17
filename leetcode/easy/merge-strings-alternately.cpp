#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string mergeAlternately(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size(), mn = min(n1, n2);
    string ans(n1+n2, '.');
    int idx = 0;
    for (int i = 0; i < mn; i++) {
        ans[idx++] = word1[i];
        ans[idx++] = word2[i];
    }
    if (n1 > n2) {
        for (int i = mn; i < n1; i++) ans[idx++] = word1[i];
    } else {
        for (int i = mn; i < n2; i++) ans[idx++] = word2[i];
    }

    return ans;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string word1, word2; cin >> word1 >> word2;
    cout << mergeAlternately(word1, word2) << endl;

    return 0;
}
