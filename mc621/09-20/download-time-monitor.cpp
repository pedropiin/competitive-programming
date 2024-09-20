#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int b, t1, a1, t2, a2;
        cin >> b >> t1 >> a1 >> t2 >> a2;

        float rem1 = (float)a1 / (float)b;
        float rem2 = (float)a2 / (float)b;

        float used1 = 0;
        float used2 = 0;

        if (rem1 <= (t2 - t1)) {
            cout << rem1 << " " << rem2 << endl;
        } else {
            rem1 = a1 - ((float)(t2 - t1) / (float)b);
            used1 += (float)(t2 - t1) / (float)b;

            float div1 = (float)rem1 / (float)((float)b / (float)2);
            float div2 = (float)a2 / (float)((float)b / (float)2);

            if (div1 < div2) {
                used1 += div1;
                rem2 = (float)(a2) - ((float)div1 * (float)b / (float)2);
                used2 += (float)rem2 / (float)b;
                cout << used1 << " " << used2 << endl;
            } else if (div2 < div1) {
                used1 += div2;
                rem1 = (float)(a1) - ((float)div2 * (float)b / (float)2);
                used1 += (float)rem1 / (float)b;
                cout << rem1 << " " << div2 << endl;
            } else {
                cout << t2 + div1 << " " << div2 << endl;
            }
        }
    }

    return 0;
}