// LEETCODE 932

class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> result;
        result.push_back(1); // Start with 1
        while (result.size() < n) {
            vector<int> temp;
            // Generate odd numbers
            for (int num : result) {
                if (2 * num - 1 <= n) // Ensure the number does not exceed n
                    temp.push_back(2 * num - 1);
            }
            // Generate even numbers
            for (int num : result) {
                if (2 * num <= n) // Ensure the number does not exceed n
                    temp.push_back(2 * num);
            }
            result = temp;
        }
        return result;
    }
};