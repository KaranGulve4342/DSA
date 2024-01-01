// LEETCODE 456

/*
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        int next = INT_MIN;
        for(int i= n-1;i >= 0;i--){
            if(nums[i] < next){
                return true;
            }
            while(!st.empty() && nums[i] > st.top()){
                next = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
*/