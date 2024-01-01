// LEETCODE 239

/*
Class Solution{
    public:
    vector<int> maxSlidingWindow(vector<int>& arr,int k){
        vector<int> ans;
        int n = arr.size();
        for(int i = 0;i < n-k+1;i++){
            int mx = INT_MIN;
            for(int j = i;j < i+k;j++){
                mx = max(mx,arr[j]);
            }
            ans.push_back(mx);
        }
    }
}

*/
/*
// Method 2: Using a stack [next greater element]


class Solution{
    public:
    vector<int> maxSlidingWindow(vector<int>& arr,int k){
        vector<int> ans;
        int n = arr.size();
        int ngi[n];
        stack<int> st;
        ngi[n - 1] = n;
        st.push(n-1);
        for(int i = n-2;i >= 0;i--){
            while(st.size() > 0 && arr[st.top()] <= arr[i]){
                st.pop();
            }
            if(st.size() == 0) ngi[i] = n;
            else ngi[i] = st.top();
            st.push(i);
        }
        vector<int> ans;
        int j = 0;
        for(int i = 0;i < n-k;i++){
            if(j < i) j = i;
            int mx = arr[j]; // starting of window se
            while(j < i+k) // means if nge is inside the window
            {
                mx = arr[j];
                if(nge[j] >= i+k) break;
                j = ngi[j];
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
/*



*/