#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define l_child(v) (2 * v)
#define r_child(v) (2 * v + 1)

const int max_n = 200005;

struct node {
    ll val = 0;
    int left, right;
};

vector<int> arr(2 * max_n);
vector<node> seg_tree(4 * max_n);
int n; // array size
int sz = 0; // segtree size

void build_seg_tree(int v, int l, int r) {


    if (l == r) {
        seg_tree[v].val = arr[l];
        seg_tree[v].left = l;
        seg_tree[v].right = r;
    } else {
        int m = l + (r - l) / 2;
        build_seg_tree(l_child(v), l, m);
        build_seg_tree(r_child(v), m + 1, r);
        seg_tree[v].val = seg_tree[l_child(v)].val + seg_tree[r_child(v)].val;
        seg_tree[v].left = l;
        seg_tree[v].right = r;
    }
    sz++;
}

ll query(int v, int l, int r) {
    if (seg_tree[v].left >= l && seg_tree[v].right <= r) {
        return seg_tree[v].val;
    } else if (seg_tree[v].right < l || seg_tree[v].left > r) {
        return 0;
    }
    return query(l_child(v), l, r) + query(r_child(v), l, r);
}

void update(int i, int x) {
    int idx = i + sz - n;
    seg_tree[idx].val = x;
    for (int j = idx / 2; j != 0; j /= 2) {
        seg_tree[j].val = seg_tree[l_child(j)].val + seg_tree[r_child(j)].val;
    }
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (__builtin_popcount(n) != 1) {
        arr[n++] = 0;
    }

    build_seg_tree(1, 0, n - 1);

    int a, b, k;
    for (int i = 0; i < q; i++) {
        cin >> k >> a >> b;
        if (k == 1) {
            update(a, b);
        } else {
            cout << query(1, --a, --b) << endl;
        }
    }

    return 0;
}