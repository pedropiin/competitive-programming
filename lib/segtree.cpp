#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define l_child(v) (2 * v)
#define r_child(v) (2 * v + 1)

const int max_n = 200005;

struct node {
    ll val;
    int left, right;
};

vector<int> arr(2 * max_n);
vector<node> seg_tree(4 * max_n);
int n;
int sz = 0;

void build_seg_tree(int v, int l, int r) {
    if (l == r) {
        seg_tree[v].val = arr[l];
        seg_tree[v].left = l;
        seg_tree[v].right = r;
    } else {
        int m = l + (r - l) / 2;
        build_seg_tree(l_child(v), l, m);
        build_seg_tree(r_child(v), m + 1, r);
        seg_tree[v].val = seg_tree[l_child(v)].val + seg_tree[r_child(v)].val; // change operation based on problem, e.g., min() for min queries
        seg_tree[v].left = l;
        seg_tree[v].right = r;
    }
    sz++;
}

ll query(int v, int l, int r) {
    if (seg_tree[v].left >= l && seg_tree[v].right <= r) {
        return seg_tree[v].val;
    } else if (seg_tree[v].right < l || seg_tree[v].left > r) {
        return 0; // change value based on problem, e.g., inf for min problems.
    }
    return query(l_child(v), l, r) + query(r_child(v), l, r); // change operation based on problem, e.g., min() for min queries
}

void update(int i, int x) {
    int idx = i + sz - n;
    seg_tree[idx].val = x;
    for (int j = idx / 2; j != 0; j /= 2) {
        seg_tree[j].val = seg_tree[l_child(j)].val + seg_tree[r_child(j)].val; // change operation based on problem, e.g., min() for min queries
    }
}

int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (__builtin_popcount(n) != 1) {
        arr[n++] = 0;
    }

    return 0;
}