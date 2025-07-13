#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    bool isValid(string s) {
        stack<int8_t> st;
        for (char c : s) {
            switch (c) {
                case '(':
                    st.push(0);
                    break;
                case '{':
                    st.push(1);
                    break;
                case '[':
                    st.push(2);
                    break;
                case ')':
                    if (st.size() == 0 || st.top() != 0) return false;
                    st.pop();
                    break;
                case '}':
                    if (st.size() == 0 || st.top() != 1) return false;
                    st.pop();
                    break;
                case ']':
                    if (st.size() == 0 || st.top() != 2) return false;
                    st.pop();
                    break;  
            }
        } 
        if (st.size() > 0) return false;
        return true;    
    }
};

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s = "()";

    Solution solve;
    cout << solve.isValid(solve) << endl;

    return 0;
}