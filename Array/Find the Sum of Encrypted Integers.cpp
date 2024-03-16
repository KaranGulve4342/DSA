// LEETCODE 3079

class Solution {
public:
    int encrypt(int x) {
        string str_x = to_string(x);
        char max_digit = *max_element(str_x.begin(), str_x.end());
        string encrypted_num(str_x.size(), max_digit);
        return stoi(encrypted_num);
    }
    
    int sumOfEncryptedInt(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            int encrypted = encrypt(num);
            total += encrypted;
        }
        return total;
    }
};