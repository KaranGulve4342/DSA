// LEETCODE 3074

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for(int i = 0;i < apple.size();i++){
            sum += apple[i];
        }
        sort(capacity.begin(), capacity.end(), greater<int>());
        
        int neededBoxes = 0;
        int apples = 0;
        
        for (int i = 0; i < capacity.size(); i++) {
            if (apples >= sum) {
                break;
            }
            if (capacity[i] >= sum - apples) {
                neededBoxes++;
                break;
            } else {
                neededBoxes++;
                apples += capacity[i];
            }
        }
        
        return neededBoxes;
    }
};