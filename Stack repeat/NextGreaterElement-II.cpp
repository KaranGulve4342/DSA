// LEETCODE 503

/*
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n,-1);

    for(int i = n-1;i >= 0;i--){
        st.push(nums[i]);

    }
    for(int i = n-1;i >= 0;i--){
        while(st.size() > 0 && st.top() <= nums[i]){
            st.pop();
        }
        if(st.size() > 0) ans[i] = st.top();
        st.push(nums[i]);
    }
    return ans;
*/