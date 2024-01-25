// LEETCODE 347

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool comp(pair<int, int> p1, pair<int, int> p2) {
        if (p1.second == p2.second) {
            return p1.first > p2.first;
        }
        return p1.second > p2.second;
    }

    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int,int> mp;
        priority_queue<pair<int,int> > pq;
        for(auto it:nums)mp[it]++;
      
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends


/*
class Solution {
public:
    // bool cmp()(pair<int, string>p1 , pair<int, string>p2){
    //     if(p1.first == p2.first){
    //         return p1.second > p2.second;
    //     }
    //     else{
    //         return p1.first < p2.first;
    //     }
    // }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        vector<string> ans;
        unordered_map<string, int> umap;
        for(auto str : words){
            umap[str]++;
        }
        priority_queue<pair<int, string>> pq;
        for(auto mp : umap){
            pq.push({-mp.second, mp.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }

};
*/

/*
class Solution{
public:
    typedef pair<int, int> pi;

    vector<int> topKFrequent(vector<int>& arr, int k){
        unordered_map<int, int> mp;

        for(int ele : arr){
            mp[ele]++;
        }

        priority_queue<int, vector<pi>, greater<pi>> pq;
        for(auto x : mp){
            int ele = x.first;
            int freq = x.second;

            pair<int, int> p = {freq, ele};
            pq.push(p);

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(pq.size() > 0){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }

        return ans;
    }
};
*/