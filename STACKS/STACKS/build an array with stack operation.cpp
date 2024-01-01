// LEETCODE 1441

/*

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> st;
        int i = 0;
        int count = 1;
        while(i < target.size()){
            st.push(count);
            ans.push_back("Push");
            count++;

            if(st.top() != target[i]){
                st.pop();
                ans.push_back("Pop");
            }
            else{
                i++;
            }
        }
        return ans;
    }
};

*/