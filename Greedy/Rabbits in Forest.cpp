// LEETCODE 781

/*
class Solution{
public:
    int numRabbits(vector<int>& answers){
        unordered_map<int, int> mp;
        int result = 0;
        for(int i = 0;i < answers.size();i++){
            if(!mp[answers[i] + 1]){
                result += answers[i] + 1; // we started a new color group
                if(answers[i] == 0) continue;
                mp[answers[i] + 1] = 1;
            }
            else{
                mp[answers[i] + 1]++;
                int key = answers[i] + 1;
                int val = mp[key];
                if(key == val){
                    // we found all the rabbits of the group
                    // eliminate the group
                    mp.erase(key);
                }
            }
        }
        return result;
    }
}
*/