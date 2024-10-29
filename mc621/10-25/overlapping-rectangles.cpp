#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX_SIZE 10000

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin;
        // vector to store the four points of a rectangle
        // [0] = low_left, [1] = upper right, [2] = upper_left, [3] = lower right
        vector<pair<int, int>> rect1(4), rect2(4);
        cin >> rect1[0].first >> rect1[0].second >> rect1[1].first >> rect1[1].second >> rect2[0].first >> rect2[0].second >> rect2[1].first >> rect2[1].second;

        rect1[2] = make_pair(rect1[0].first, rect1[1].second);
        rect1[3] = make_pair(rect1[1].first, rect1[0].second);

        rect2[2] = make_pair(rect2[0].first, rect2[1].second);
        rect2[3] = make_pair(rect2[1].first, rect2[0].second);

        vector<vector<int>> cart_plane(MAX_SIZE, vector<int>(MAX_SIZE, 0));

        // initializing plane
        for (int i = 0; i < MAX_SIZE; i++) {
            if (i < rect1[0].first || i > rect1[1].first) {
                continue;
            }
            for (int j = 0; j < MAX_SIZE; j++) {
                if (j < rect1[0].second || j > rect1[1].second) {
                    continue;
                }
                cart_plane[i][j] = 1;
            }
        }

        int first_time = 1;
        int x_lowleft, y_lowleft, x_upright, y_upright;
        for (int i = rect2[0].first; i <= rect2[1].first; i++) {
            for (int j = rect2[0].second; j <= rect2[1].second; j++) {
                if (cart_plane[i][j] == 1) {
                    if (first_time) {
                        x_lowleft = i;
                        first_time == 0;
                        continue;
                    } 
                    
                }
            }
        }
    }

    return 0;
}