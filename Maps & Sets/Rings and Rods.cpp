// LEETCODE 2103

/*
class Solution {
public:
    int countPoints(string rings) {
        if(rings.length() < 6){
            return 0;
        }
        unordered_map<int, unordered_map<char, int>>rods;
        int n = rings.length()/2;

        for(int i = 0;i < n;i++){
            int color = rings[2*i];
            int rod = rings[2*i + 1] - '0';

            rods[rod][color]++;
        }

        int count = 0;
        for(auto rgb : rods){
            if(rgb.second.size() == 3){
                count++;
            }
        }
        return count;
    }
};
*/