#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    string solve_op(pair<string, pair<string, string>> op) {
        if (op.first == "+") {
            return to_string(stoi(op.second.first) + stoi(op.second.second));
        } else if (op.first == "-") {
            return to_string(stoi(op.second.first) - stoi(op.second.second));
        } else if (op.first == "*") {
            return to_string(stoi(op.second.first) * stoi(op.second.second));
        } else {
            return to_string(stoi(op.second.first) / stoi(op.second.second));
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<pair<string, pair<string, string>>> s;
        int n = tokens.size();
        int ans;
        if (tokens.size() == 1) ans = stoi(tokens[0]);
        else {
            for (int i = n - 1; i >= 0; i--) {
                string tok = tokens[i];
                if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                    s.push({tok, {"n", "n"}});
                } else {
                    if (s.top().second.second == "n") {
                        s.top().second.second = tok;
                    } else {
                        s.top().second.first = tok;
                        do {
                            string res = solve_op(s.top());
                            cout << "solved with res = " << res << endl;
                            s.pop();
                            if (s.size() == 0) {
                                ans = stoi(res);
                                break;
                            }
                            if (s.top().second.second == "n") {
                                s.top().second.second = res;
                                break;
                            } else {
                                s.top().second.first = res;
                            }
                        } while (s.top().second.first != "n");
                    }
                }
            }
        }
        return ans;
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution solve;
    cout << solve.evalRPN(tokens) << endl;

    return 0;
}