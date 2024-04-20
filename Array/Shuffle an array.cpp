// LEETCODE 384

class Solution {
public:
    vector<int> original;
    vector<int> pure;
    Solution(vector<int>& nums) {
        original = nums;
        pure = nums;
    }
    
    vector<int> reset() {
        return pure;
    }
    
    vector<int> shuffle() {
        vector<int> temp = original;
        for(int i = 0; i < original.size(); i++){
            int n = temp.size();
            int randIdx = std::rand() % n;
            original[i] = temp[randIdx];
            temp.erase(temp.begin() + randIdx);
        }

        return original;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */