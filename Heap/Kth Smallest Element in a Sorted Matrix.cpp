// LEETCODE 378

/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                min_heap.push(matrix[i][j]);
            }
        }

        int result = 0;
        while (k > 0) {
            result = min_heap.top();
            min_heap.pop();
            k--;
        }

        return result;
    }
};
*/