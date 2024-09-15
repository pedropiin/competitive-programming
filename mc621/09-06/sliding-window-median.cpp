#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Solution idea taken from USACO Guide
void add(multiset<int> &small, multiset<int> &big, int elem, int k) {
    int med = *small.rbegin();

    if (med < elem) {
        big.insert(elem);
        if (big.size() > (k / 2)) {
            multiset<int>::iterator temp_it = big.begin();
            small.insert(*temp_it);
            big.erase(big.find(*temp_it));
        } 
    } else {
        small.insert(elem);
        if (small.size() > ((k + 1) / 2)) {
            int temp = *small.rbegin();
            big.insert(temp);
            small.erase(small.find(temp));
        }
    }
}


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    multiset<int> small;
    multiset<int> big;
    small.insert(v[0]);

    for (int i = 1; i < k; i++) {
        add(small, big, v[i], k);
    }
    cout << *small.rbegin() << " ";
    for (int i = k; i < n; i++) {
        if (k != 1) {
            multiset<int>::iterator temp_it = big.find(v[i - k]);
            if (temp_it != big.end()) {
                big.erase(temp_it);
            } else {
                small.erase(small.find(v[i - k]));
            }

            if (small.empty()) {
                temp_it = big.begin();
                small.insert(*temp_it);
                big.erase(temp_it);
            }

            add(small, big, v[i], k);
        } else {
            add(small, big, v[i], k);

            multiset<int>::iterator temp_it = big.find(v[i - k]);
            if (temp_it != big.end()) {
                big.erase(temp_it);
            } else {
                small.erase(small.find(v[i - k]));
            }

            if (small.empty()) {
                temp_it = big.begin();
                small.insert(*temp_it);
                big.erase(temp_it);
            }
        }
        cout << *small.rbegin() << " ";
    }
    cout << endl;

    return 0;
}