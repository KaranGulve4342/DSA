// LEETCODE 1944
/*
class Solution{
    public:
    vector<int> canSeePersonsCount(vector<int>&arr){
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        st.push(arr[n-1]);
        ans[n-1] = 0;
        for(int i = n - 2;i >= 0;i--){
            int count = 0;
            while(st.size() > 0 && arr[i] > st.top()){
                st.pop();
                count++;
            }
            if(st.size()!=0) count++; // VIMP
            ans[i] = count;
            st.push(arr[i]);
        }
        return ans;
    }
}
*/
/*
vector<int> canSeePersonsCount(vector<int>&v){
        int n = v.size();

        vector<int> ans(n,0);
        stack<int> st;
        st.push(v[n-1]);
        ans[n-1] = 0;
        for(int i = n-2;i >= 0;i--){
            int count = 0;
            while(st.size() > 0 && v[i] > st.top()){
                st.pop();
                count++;
            }
            if(st.size() != 0) count++;
            ans[i] = count;
            st.push(ans[i]);

        }
        return ans;
    }
*/