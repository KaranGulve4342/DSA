// LEETCODE 1190

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        int len = s.length();
        int i = 0;

        for(int i = 0;i < len;i++){
            st.push(s[i]);
            if(s[i] == ')'){
                st.pop();
                string temp = "";
                while(st.top() != '('){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for(int j = 0;j < temp.size();j++){
                    st.push(temp[j]);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};