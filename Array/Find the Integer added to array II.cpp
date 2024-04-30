// Leetcode 3132

class Solution {
public:
    bool solve(vector<int>& nums1, vector<int>& nums2){
        int i = 0;
        int j = 0;
        int left = 2;
        
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                i++;
                j++;
            }
            else{
                i++;
                left--;
                if(left < 0){
                    return false;
                }
            }
        }
        
        return j = nums2.size() && (i - j) <= 2;
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        unordered_map<int, int> counts;
        
        int answer = INT_MAX;
        
        int m = nums1.size();
        int n = nums2.size();
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                int differ = nums2[j] - nums1[i];
                counts[differ]++;
            }
        }
        
        for(auto x : counts){
            vector<int> temp(m);
            for(int i = 0;i < m;i++){
                temp[i] = nums1[i] + x.first;
            }
            
            sort(temp.begin(), temp.end());
            
            if(solve(temp, nums2)){
                answer = min(answer, x.first);
            }
        }
        
        return answer;
        
        
    }
};

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int ans = INT_MAX;

        for(int i = 0;i < nums1.size();i++){
            for(int j = i+1;j < nums1.size();j++){
                vector<int> updatedNums1;

                for(int k = 0;k < nums1.size();k++){
                    if(k == i || k == j) continue;
                    updatedNums1.push_back(nums1[k]);
                }

                int flag = 1;
                int diff = nums2[0] - updatedNums1[0];
                for(int k = 1;k < updatedNums1.size();k++){
                    if(nums2[k] - updatedNums1[k] != diff){
                        flag = 0;
                    }
                }
                if(flag == 1){
                    ans = min(ans, diff);
                }
            }
        }
        return ans;
    }
};