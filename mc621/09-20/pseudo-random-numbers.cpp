#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int z, i, m, l;
    cin >> z >> i >> m >> l;

    map<int, int>::iterator it;
    int num_cases = 1;
    while(z != 0 && i != 0 && m != 0 && l != 0) {
        map<int, int> rnums;
        int count = 0;

        rnums.insert(std::pair<int, int>(l, count));
        count++;
        while (1) {
            l = (z * l + i) % m;
            it = rnums.find(l);
            if (it != rnums.end()) { 
                cout << "Case " << num_cases << ": " << (count - it->second) << endl;
                break;
            }
            rnums.insert(std::pair<int, int>(l, count));
            count++;
        }
        num_cases++;
        cin >> z >> i >> m >> l;
    }

    return 0;
}