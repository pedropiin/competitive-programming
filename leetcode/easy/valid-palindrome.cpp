#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        uint8_t c1, c2;
        while (l < r) {
            c1 = tolower(s[l]); c2 = tolower(s[r]);
            if ((c1 >= 'a' && c1 <= 'z') || (c1 >= '0' && c1 <= '9')) {
                if ((c2 >= 'a' && c2 <= 'z') || (c2 >= '0' && c2 <= '9')) {
                    if (c1 == c2) {
                        l++;r--;
                        continue;
                    }
                    else return false;
                }
                r--;
                continue;
            }
            l++;
        }
        return true;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s = "A man, a plan, a canal: Panama";
    Solution solve;
    cout << solve.isPalindrome(s) << endl;

    return 0;
}