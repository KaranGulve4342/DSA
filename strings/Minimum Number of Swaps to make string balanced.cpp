// LEETCODE 1963 

class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        stack<char> st;
        for(int i = 0;i < s.length();i++){
            if(s[i] == '['){
                st.push(s[i]);
            }
            if(s[i] == ']' && !st.empty() && st.top() == '['){
                st.pop();
            }
        }
        count = st.size();
        if(count % 2 == 0){
            return count/2;
        }
        return (count+1)/2;
    }
};