// LEETCODE 11

/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = 0;
        while(left < right){
            maxArea = max(maxArea, (min(height[left], height[right])*(right-left)));
            if(height[left] < height[right]) left++;
            else right--;
        }
        // for(int i = 0;i < height.size()-1;i++){
        //     for(int j = i;j < height.size();j++){
        //         maxArea = max(maxArea, (min(height[i], height[j]) * abs(i-j)));
        //     }
        // }
        return maxArea;
    }
};
*/