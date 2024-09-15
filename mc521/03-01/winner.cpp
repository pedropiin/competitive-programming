#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, score_rodada, score_max = 0;
    string player_rodada, player_max;
    map <string, int> map_player;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> player_rodada;
        cin >> score_rodada;
        if (map_player.find(player_rodada) == map_player.end()) {
            map_player[player_rodada] = score_rodada;
        } else {
            map_player[player_rodada] += score_rodada;
        }

        if (map_player[player_rodada] > map_player[player_max]) {
            player_max = player_rodada;
            // score_max = map_player[player_rodada];
        }
    }

    cout << player_max << endl;

    return 0;
}