//  LEETCODE 2491

class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        long long n = skills.size();
        long long sum = 0;

        for (auto skill : skills) {
            sum += skill;
        }
        
        if (sum % (n / 2) != 0) {
            return -1;
        }
        
        long long target = sum / (n / 2);
        
        sort(skills.begin(), skills.end());
        
        long long product = 0;
        
        int left = 0;
        int right = n - 1;
        
        while (left < right){
            if (skills[left] + skills[right] != target) {
                return -1;
            }
            
            product += skills[left] * skills[right];
            
            left++;
            right--;
        }
        
        return product;
    }
};