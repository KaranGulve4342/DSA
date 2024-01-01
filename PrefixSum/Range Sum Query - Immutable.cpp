// LC 303
/*

class NumArray {
public:
    vector<int> prefix_Sum;
    NumArray(vector<int>& nums) {
        prefix_Sum = vector<int>(nums.size());
        prefix_Sum[0] = nums[0];
        int n = nums.size();
        for(int i = 1;i < n;i++) prefix_Sum[i] = prefix_Sum[i-1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefix_Sum[right];
        else return prefix_Sum[right] - prefix_Sum[left-1];
    }
};

*/
