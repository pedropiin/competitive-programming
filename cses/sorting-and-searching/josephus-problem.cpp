#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    queue <int> fila;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        fila.push(i + 1);
    }
 
    int frente, removido;
    while (!fila.empty()) {
        frente = fila.front();
        fila.pop();
        fila.push(frente);
        removido = fila.front();
        fila.pop();
        cout << removido << ' ';
    }
    cout << endl;
 
    return 0;
}

