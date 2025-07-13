#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class MinStack {
    public:
        stack<pair<int, int>> s;
        int min_elem;

        MinStack() {
            s = stack<pair<int, int>>();
        }

        void push(int val) {
            if (s.size() == 0) min_elem = val;
            else min_elem = min(min_elem, val);
            s.push(make_pair(val, min_elem));
        }

        void pop() {
            int prev_min = s.top().second;
            s.pop();
            if (s.size() != 0) min_elem = s.top().second;
            else min_elem = 2147483647;
        }

        int top() {
            return s.top().first;
        }

        int getMin() {
            return s.top().second;
        }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> cmds(n);
    for (int i = 0; i < n; i++) cin >> cmds[i];
    vector<int> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];

    MinStack* obj = new MinStack();
    for (int i = 0; i < n; i++) {
        if (cmds[i] == "push") {
            obj->push(vals[i]);
            continue;
        } 
        if (cmds[i] == "pop") {
            obj->pop();
            continue;
        }
        if (cmds[i] == "top") {
            cout << obj->top() << endl;
            continue;
        }
        if (cmds[i] == "getMin") {
            cout << obj->getMin() << endl;
            continue;
        }
    }

    return 0;
}