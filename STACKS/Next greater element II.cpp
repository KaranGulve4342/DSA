
/*
vector<int> nextGreaterElements(vector<int>& arr){
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n,-1);
    for(int i = n-1;i >= 0;i--){
        st.push(arr[i]);
    }
    for(int i = n-1;i >= 0;i--){
        while(st.size() > 0 && st.top() <= arr[i]) st.pop();
        if(st.size() > 0) ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}
*/
