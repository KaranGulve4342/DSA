// LEETCODE 239

// BRUTE FORCE APPROACH

/*
vector<int> maxSlidingWindow(vector<int>& arr, int k){
    vector<int> ans;
    int n = arr.size();
    for(int i = 0;i < n-k+1;i++){
        int mx = INT_MIN:
        for(int j = i;j < i+k;j++){
            mx = max(mx, arr[j]);
        }
        ans.push_back(mx);
    }
}
*/

/*
vector<int> maxSlidingWindow(vector<int>& arr,int k){
    if(k == 1) return arr;
    int n = arr.size();
    int ngi[n];
    stact<int> st;
    ngi[n-1] = n;
    st.push(n-1);
    for(int i = n-1;i >= 0;i--){
        while(st.size() > 0 && arr[st.top()] <= arr[i]){
            st.pop();
        }
        if(st.size() == 0) ngi[i] = n;
        else ngi[i] = st.top();
        st.push(i);
    }
    vector<int> ans;
    int j = 0;
    for(int i = 0;i < n-k+1;i++){
        if(j < i) j = i;
        int mx = arr[j]; // starting window se
        while(j < i+k){
            mx = arr[j];
            if(ngi[j] >= i+k) break;
            j = ngi[j];
        }
        ans.push_back(mx);
    }
    return ans;
}
*/
