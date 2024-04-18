// LEETCODE 1006

class Solution {
public:
    int clumsy(int n) {
        vector<char> operations = {'*', '/', '+', '-'};
        stack<int> st;

        st.push(n--);
        int idx = 0;

        while(n > 0){
            int top = st.top();
            st.pop();

            if(operations[idx] == '*'){
                st.push(top * (n--));
            }
            else if(operations[idx] == '/'){
                st.push(top / (n--));
            }
            else if(operations[idx] == '+'){
                st.push(top + (n--));
            }
            else{
                st.push(top);
                st.push((-1)*(n--));
            }

            idx = (idx + 1)%4;
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};