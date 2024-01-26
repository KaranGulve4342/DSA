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

/*
class Solution{
public:
    string reorganizeString(string s){

        unordered_map<char, int> mp;
        priority_queue<pair<int, char> >pq;

        for(auto x : s){
            mp[x]++;
        }

        for(auto x : mp){
            pq.push({x.second, x.first});
        }

        string ans = "";

        while(pq.size() > 1){
            auto one = pq.top();
            pq.pop();
            auto two = pq.top();
            pq.pop();

            ans += one.second;
            ans += two.second;

            if(--one.first){
                pq.push({one.first, one.second});
            }
            if(--two.second){
                pq.push({two.first, two.second});
            }
        }

        if(!pq.empty()){
            if(pq.top().first > 1) return "";
            else if(ans.size() > 0 && pq.top().second == ans.back()) return "";
            else ans += pq.top().second;
        }

        return ans;

    }
}
*/