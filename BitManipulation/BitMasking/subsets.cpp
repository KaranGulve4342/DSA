#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> ans;
    int subset_count = 1<<n;

    for(int mask = 0;mask < subset_count;mask++){
        vector<int> subset;
        for(int i = 0;i < n;i++){
            if(mask & (1 << i)){
                subset.push_back(nums[i]);
            }
        }
        ans.push_back(subsets);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    vector<vector<int>> ans = subsets(v);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}