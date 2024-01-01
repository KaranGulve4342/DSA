// LEETCODE 1338

/*
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> umap;
        for(auto num : arr){
            umap[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto mp : umap){
            pq.push({mp.second, mp.first});
        }
        int count = 0;
        int removed_ele = 0;
        while(!pq.empty()){
            int temp = pq.top().first;
            pq.pop();
            removed_ele += temp;
            count++;

            if(removed_ele >= n/2){
                return count;
            }
        }
        return -1;

    }
};
*/