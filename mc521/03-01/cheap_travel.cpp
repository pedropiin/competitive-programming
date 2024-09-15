#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    
    int viagens_ticket = n / m, resto = n % m;
    int mistura = (viagens_ticket * b) + (resto * a), sole_ticket = n * a, mul_tickets = (viagens_ticket + 1) * b;

    cout << min({mistura, sole_ticket, mul_tickets}) << endl;

    return 0;
}