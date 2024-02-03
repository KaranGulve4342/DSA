// LEETCODE 962

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;

        for(int i = 0;i < nums.size();i++){
            if(st.empty() || nums[st.top()] > nums[i]){
                st.push(i);
            }
        }
        int maxWidth = INT_MIN;
        for(int i = nums.size()-1;i >= 0;i--){
            while(st.size() > 0 && nums[st.top()] <= nums[i]){
                maxWidth = max(maxWidth, i - st.top());
                st.pop();
            }
        }

        return maxWidth;
    }
};