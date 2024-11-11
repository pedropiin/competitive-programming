#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define l_child(v) (2 * v)
#define r_child(v) (2 * v + 1)

const int max_n = 200005;
const int inf = INT_MAX;

struct node {
    int val = -1;
    int left, right;
};

vector<int> arr(max_n);
vector<node> seg_tree(4 * max_n);

void build_seg_tree(int v, int l, int r) {
    if (l == r) {
        seg_tree[v].val = arr[l];
        seg_tree[v].left = l;
        seg_tree[v].right = r;
    } else {
        int m = l + (r - l) / 2;
        build_seg_tree(l_child(v), l, m);
        build_seg_tree(r_child(v), m + 1, r);
        seg_tree[v].val = min(seg_tree[l_child(v)].val, seg_tree[r_child(v)].val);
        seg_tree[v].left = l;
        seg_tree[v].right = r;
    }
}

int query(int v, int l, int r) {
    if (seg_tree[v].left >= l && seg_tree[v].right <= r) {
        return seg_tree[v].val;
    } else if (seg_tree[v].right < l || seg_tree[v].left > r) {
        return inf;
    }
    return min(query(l_child(v), l, r), query(r_child(v), l, r));
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build_seg_tree(1, 0, n - 1);

    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << query(1, a - 1, b - 1) << endl;;
    }

    return 0;
}