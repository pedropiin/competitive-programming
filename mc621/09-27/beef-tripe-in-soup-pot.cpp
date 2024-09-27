#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> spicy;
    vector<pair<int, int>> soup;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (c && !d) {
            // can only be cooked on spicy hot pot
            spicy.push_back(pair<int, int>(a, i+1));
        } else if (!c && d) {
            // can only be cooked on soup pot
            soup.push_back(pair<int, int>(b, i+1));
        } else {
            // can be cooked in both spicy hot pot and soup pot
            a > b ? soup.push_back(pair<int, int>(b, i+1)) : spicy.push_back(pair<int, int>(a, i+1));
        }
    }

    sort(spicy.begin(), spicy.end(), [](const pair<int, int> &left, const pair<int, int> &right) {
        return left.first < right.first;
    });
    sort(soup.begin(), soup.end(), [](const pair<int, int> &left, const pair<int, int> &right) {
        return left.first < right.first;
    });


    int temp = spicy.size();
    cout << temp << " ";
    for (int i = 0; i < temp; i++) {
        cout << spicy[i].second << " ";
    }
    cout << endl;

    temp = soup.size();
    cout << temp << " ";
    for (int i = 0; i < temp; i++) {
        cout << soup[i].second << " ";
    }
    cout << endl;

    return 0;
}