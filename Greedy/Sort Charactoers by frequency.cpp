// LEETCODE 451

#include <bits/stdc++.h>
using namespace std;

#define pp pair<int, char>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(int i = 0;i < s.size(); i++){
            mp[s[i]]++;
        }
        priority_queue<pp> pq;
        for(auto entry : mp) {
            char key = entry.first;
            int val = entry.second;
            pq.push({val, key});
        }
        string result = "";
        while(not pq.empty()){
            pp curr = pq.top();
            pq.pop();
            for(int i = 0;i < curr.first;i++){
                result += curr.second;
            }
        }
        return result;
    }
};

int main()
{
    
    
    return 0;
}