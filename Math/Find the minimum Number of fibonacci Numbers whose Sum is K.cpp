// LEETCODE 1414

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibonacci = {1, 1};
        while (fibonacci.back() < k) {
            fibonacci.push_back(fibonacci[fibonacci.size() - 1] + fibonacci[fibonacci.size() - 2]);
        }
        
        int count = 0;
        int index = fibonacci.size() - 1;
        
        while (k > 0) {
            while (fibonacci[index] > k) {
                index--;
            }
            k -= fibonacci[index];
            count++;
        }
        
        return count;
    }
};