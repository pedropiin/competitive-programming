#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int anal_prefix(string prefix, string candidate) {
    for (int i = 0; i < prefix.length(); i++) {
        if (candidate[i] != prefix[i]) {
            return 0;
        }
    }

    return 1;
}

void copy_string(string &og, string &dest, int len) {
    cout << "ENTERING COPY STRING" << endl;
    cout << "og string is " << og << endl;
    cout << "dest string is " << dest << endl;
    cout << "current len is " << len << endl;
    for (int i = 0; i < len; i++) {
        dest[i] = og[i];
    }
    dest[len] = '\0';
    cout << "now dest is " << dest << endl;
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<string> v(n);
    int size_bigg = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i].length() > size_bigg) {
            size_bigg = v[i].length();
        }
    }

    sort(v.begin(), v.end());

    int res = 0;
    while (n > 0) {
        if (n < k) {
            res++;
            break;
        }
        string cur_prefix;
        for (int len = 1; len < size_bigg; len++) {
            cout << "curr size is = " << len << endl;
            cout << "strings are: ";
            for (int i = 0; i < n; i++) {
                cout << v[i] << endl;
            }
            int cur_count = 0;
            int big_count = 0;
            int i_cur_prefix = 0;
            int i_big_prefix = 0;
            copy_string(v[0], cur_prefix, len);
            cout << "curr prefix is = " << cur_prefix << endl;
            for (int i = 0; i < n; i++) {
                if (anal_prefix(cur_prefix, v[i])) {
                    cur_count++;
                } else {
                    if (cur_count > big_count) {
                        big_count = cur_count;
                        i_big_prefix = i_cur_prefix;
                    }
                copy_string(v[i], cur_prefix, len);
                }
            }

            if (big_count < k) {
                v.erase(v.begin() + i_big_prefix, v.begin() + i_big_prefix + big_count);
                n -= big_count;
                res++;
                break;
            }
        }
    }
    cout << res << endl;

    return 0;
}