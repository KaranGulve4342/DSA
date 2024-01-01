// LEETCODE 392

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