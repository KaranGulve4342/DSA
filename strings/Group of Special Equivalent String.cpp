// LEETCODE 893

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        set<pair<string, string>> st;

        for(auto word : words){
            pair<string, string> p;
            for(int i = 0;i < word.length();i++){
                if(i%2) p.first += word[i];
                else p.second += word[i];
            }

            sort(p.first.begin(), p.first.end());
            sort(p.second.begin(), p.second.end());

            st.insert(p);
        }
        return st.size();

    }
};