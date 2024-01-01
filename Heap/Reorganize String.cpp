// LEETCODE 767

/*
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        priority_queue<pair<int, char>>pq;
        vector<int> count(26,0);

        for(auto i : s){
            count[i - 'a']++;
            if(2*count[i - 'a'] > n + 1) return "";
        }

        for(int i = 0;i < 26;i++){
            pq.push({count[i], i + 'a'});
        }
        string ans(n, '$');
        int curr = 0;
        while(pq.size() != 0){
            auto temp = pq.top();
            pq.pop();

            int p = temp.first;

            while(p--){
                ans[curr] = temp.second;
                curr += 2;
                if(curr >= n) curr = 1;
            }
        }
        return ans;
    }
};
*/