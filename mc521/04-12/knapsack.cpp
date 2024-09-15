#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int capacidade, num_items, peso_it, valor_it;
    cin >> capacidade >> num_items;
    vector<int> peso, valor;
    for (int i = 0; i < num_items; i++) {
        cin >> peso_it >> valor_it;
        peso.push_back(peso_it);
        valor.push_back(valor_it);
    }

    int matrizdp[num_items + 1][capacidade + 1], temp;
    for (int i = 0; i <= num_items; i++) {
        for (int j = 0; j <= capacidade; j++) {
            if (i == 0 || j == 0) {
                matrizdp[i][j] = 0;
            } else if (peso[i - 1] <= j) {
                temp = max(valor[i - 1] + matrizdp[i - 1][j - peso[i - 1]], matrizdp[i - 1][j]);
                matrizdp[i][j] = temp;
            } else {
                matrizdp[i][j] = matrizdp[i - 1][j];
            }
        }
    }

    cout << matrizdp[num_items][capacidade] << endl;

    return 0;
}