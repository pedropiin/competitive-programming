#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class UnionFind {
    private:
        vector<int> p, rank, setSize;
        int numSets;

    public: 
        UnionFind(int N) {
            setSize.assign(N, 1);
            numSets = N;
            rank.assign(N, 0);
            p.assign(N, 0);
            for (int i = 0; i < N; i++) {
                p[i] = i;
            }
        }

        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }

        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                numSets--;
                int x = findSet(i), y = findSet(j);
                if (rank[x] > rank[y]) {
                    p[y] = x;
                    setSize[x] += setSize[y];
                } else {
                    p[x] = y;
                    setSize[y] += setSize[x];
                    if (rank[x] == rank[y]) {
                        rank[y]++;
                    }
                }
            }
        }

        int numDisjointSets() {
            return numSets;
        }

        int sizeOfSet(int i) {
            return setSize[findSet(i)];
        }
};

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    UnionFind cnjts(n + 1);
    while (m--) {
        int size, first, novo;
        cin >> size;
        if (size == 0) {
            continue;
        }
        cin >> first;
        for (int i = 1; i < size; i++) {
            cin >> novo;
            cnjts.unionSet(first, novo);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << cnjts.sizeOfSet(i) << " ";
    }
    cout << endl;

    return 0;
}