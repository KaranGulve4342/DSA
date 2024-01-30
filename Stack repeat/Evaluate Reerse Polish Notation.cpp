// LEETCODE 150

class Solution {
public:
    int solve(int val1, int val2, string ch) {
        if (ch == "+") return val1 + val2;
        else if (ch == "-") return val2 - val1;
        else if (ch == "*") return val1 * val2;
        else return (val2 / val1);
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto t : tokens) {
            if (t != "+" && t != "-" && t != "*" && t != "/") {
                st.push(stoi(t));
            } else {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();

                int ans = solve(val1, val2, t);
                st.push(ans);
            }
        }

        return st.top();
    }
};