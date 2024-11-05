#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        pair<int, int> ll1, ur1, ll2, ur2;
        cin >> ll1.first >> ll1.second >> ur1.first >> ur1.second >> ll2.first >> ll2.second >> ur2.first >> ur2.second;

        // idea of checking overlap taken from geeks for geeks: https://www.geeksforgeeks.org/find-two-rectangles-overlap/
        if (ll1.first >= ur2.first || ll2.first >= ur1.first || ll2.second >= ur1.second || ll1.second >= ur2.second) {
            // do not overlap
            cout << "No Overlap" << endl;
            if (t > 0) {
                cout << endl;
            }
            continue;
        } 

        // if here, they do overlap
        // idea to get overlapping area points taken from geeks for geeks: https://www.geeksforgeeks.org/total-area-two-overlapping-rectangles/
        cout << max(ll1.first, ll2.first) << " " << max(ll1.second, ll2.second) << " " << min(ur1.first, ur2.first) << " " << min(ur1.second, ur2.second) << endl;
        if (t > 0) {
            cout << endl;
        }
    }

    return 0;
}